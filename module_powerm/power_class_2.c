#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>
#include <linux/msm8974_pwm_vibrator.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 2\n");
    set_backlight_level(BRIGHTNESS_P2);
    msm8974_pwm_vibrator_gain(VIBRATOR_P2);
    set_gov_powersave_bias(PS_BIAS_VLOW);
    set_max_cpu_freq(MAX_CPUFREQ_P2);
}

const struct power_class_ops *POWER_OPS_2 = &((struct power_class_ops){ activate });
