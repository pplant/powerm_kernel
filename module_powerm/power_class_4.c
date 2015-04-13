#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>
#include <linux/msm8974_pwm_vibrator.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 4\n");
    set_backlight_level(BRIGHTNESS_P4);
    msm8974_pwm_vibrator_gain(VIBRATOR_P4);
    set_gov_powersave_bias(PS_BIAS_LOW);
    set_max_cpu_freq(MAX_CPUFREQ_P4);
}

const struct power_class_ops *POWER_OPS_4 = &((struct power_class_ops){ activate });
