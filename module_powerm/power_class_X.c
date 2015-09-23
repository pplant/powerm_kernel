#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class X\n");
    set_gov_powersave_bias(PS_BIAS_BASE);
}

static void update(void){
    printk(KERN_INFO POWER_TAG": Update power class X\n");
}

const struct power_class_ops *POWER_OPS_X = &((struct power_class_ops){ activate,update });
