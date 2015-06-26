#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>
#include <linux/msm8974_pwm_vibrator.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 3\n");
    set_backlight_level(BRIGHTNESS_P3);
    msm8974_pwm_vibrator_gain(VIBRATOR_P3);
    set_max_cpu_freq(MAX_CPUFREQ_P3);
}

const struct power_class_ops *POWER_OPS_3 = &((struct power_class_ops){ activate });
