#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 8\n");
    set_backlight_level(BRIGHTNESS_P8);
    set_max_cpu_freq(MAX_CPUFREQ_P8);
}

const struct power_class_ops *POWER_OPS_8 = &((struct power_class_ops){ activate });
