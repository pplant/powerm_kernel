#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>
#include <linux/msm8974_pwm_vibrator.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 0\n");
    set_backlight_level(BRIGHTNESS_P0);
    msm8974_pwm_vibrator_gain(VIBRATOR_P0);
    set_max_cpu_freq(MAX_CPUFREQ_P0);
    set_max_gpu_power_level(MAX_GPU_LV_P0);
}

const struct power_class_ops *POWER_OPS_0 = &((struct power_class_ops){ activate });
