#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 6\n");
    set_backlight_level(BRIGHTNESS_P6);
}

const struct power_class_ops *POWER_OPS_6 = &((struct power_class_ops){ activate });
