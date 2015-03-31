#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_ALERT */
#include <linux/power_supply.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Plant, 2015");
MODULE_DESCRIPTION("hello world module");

int init_module(void)
{
	char name[] = "battery";
	struct power_supply *psy = power_supply_get_by_name(name);
	if(psy != NULL){
		int result = 0;
		union power_supply_propval capacity;
		result = psy->get_property(psy,POWER_SUPPLY_PROP_CAPACITY,&capacity);
		if(!result){
			printk(KERN_INFO "The charge level is %d\n",capacity.intval);
		}

	}
	printk(KERN_INFO "Hello android kernel...\n");
	return 0;
}

void cleanup_module(void)
{
printk(KERN_INFO "Goodbye android kernel...\n");
}
