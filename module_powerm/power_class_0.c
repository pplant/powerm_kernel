#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 0\n");
    set_backlight_level(BRIGHTNESS_P0);
}

const struct power_class_ops *POWER_OPS_0 = &((struct power_class_ops){ activate });

