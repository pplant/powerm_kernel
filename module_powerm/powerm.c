#include <linux/module.h>   /* Needed by all modules */
#include <linux/kernel.h>   /* Needed for KERN_INFO */
#include <linux/init.h>     /* Needed for the macros */
#include <linux/jiffies.h>
#include <linux/time.h>
#include <linux/power_supply.h>

#include "include/power_class.h"
#include "include/powerm.h"

//TODO set to 300
#define DELAY 10

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Plant, 2015");
MODULE_DESCRIPTION("power management module");

static char *name = "battery";

//Used for debug only
static int force_capacity = -1;
module_param(force_capacity,int,S_IRUGO);

static struct timer_list read_timer;
static struct power_supply *psy;
static struct power_class power_c;

/* Power class check/selection methods */

static void change_power_class(int power_class_id){
	power_c = (struct power_class) { 0 };
	switch (power_class_id){
		case 0:
			power_c = (struct power_class){ POWER_OPS_0, power_class_id };
			break;
		case 1:
			power_c = (struct power_class){ POWER_OPS_1, power_class_id };
			break;
		case 2:
			power_c = (struct power_class){ POWER_OPS_2, power_class_id };
			break;
		case 3:
			power_c = (struct power_class){ POWER_OPS_3, power_class_id };
			break;
		case 4:
			power_c = (struct power_class){ POWER_OPS_4, power_class_id };
			break;
		case 5:
			power_c = (struct power_class){ POWER_OPS_5, power_class_id };
			break;
		case 6:
			power_c = (struct power_class){ POWER_OPS_6, power_class_id };
			break;
		case 7:
			power_c = (struct power_class){ POWER_OPS_7, power_class_id };
			break;
		case 8:
			power_c = (struct power_class){ POWER_OPS_8, power_class_id };
			break;
		default:
			power_c = (struct power_class) {POWER_OPS_X, power_class_id};
	}
	//activate the previously selected power_class
	activate_power_class(&power_c);
}

static void check_power_class(int capacity){
	int power_class_id = capacity/10;

	if(power_c.power_class_id != power_class_id){
		change_power_class(power_class_id);
	}
}

/* Timer methods */

static void read_battery_state(unsigned long data)
{
	int result = 0;
	union power_supply_propval capacity_val;
	printk(KERN_INFO POWER_TAG": Capacity couldn't be read\n");
	result = psy->get_property(psy,POWER_SUPPLY_PROP_CAPACITY,&capacity_val);
	if(!result){
		int capacity = capacity_val.intval;
		printk(KERN_INFO POWER_TAG": The charge level is %d\n",capacity);
		check_power_class(capacity);
	}else{
		printk(KERN_INFO POWER_TAG": Capacity couldn't be read\n");
	}

	//Read expires such that timer calls method again
	read_timer.expires = jiffies + DELAY * HZ;
	add_timer(&read_timer);
}

static void start_timer(void){
	init_timer(&read_timer);

    read_timer.function = read_battery_state;

    //Timer experies in 300 seconds = 5 min
  	read_timer.expires = jiffies + DELAY * HZ;
    add_timer(&read_timer);
    printk(KERN_INFO POWER_TAG": Periodic battery check running\n");
}


/* Methods to start end clenaup modules*/

int init_module(void)
{
	//Initalizing power_c
	power_c = (struct power_class){ POWER_OPS_X, -1 };
	if(force_capacity == -1){
		psy = power_supply_get_by_name(name);
		if(psy != NULL){
			printk(KERN_INFO POWER_TAG": Module running\n");
			start_timer();
		}else{
			printk(KERN_INFO POWER_TAG": Battery device not available!\n");
			return 1;
		}
	}else{
		printk(KERN_INFO POWER_TAG": Module running forced capacity (%d)\n",force_capacity);
		check_power_class(force_capacity);
	}

	return 0;
}

void cleanup_module(void)
{
	del_timer(&read_timer);  
	printk(KERN_INFO POWER_TAG": managment module cleaned\n");
}


