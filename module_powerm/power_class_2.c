#include "include/power_class.h"
#include "include/powerm.h"
#include "include/powerm_control.h"
#include <linux/kernel.h>
#include <linux/msm8974_pwm_vibrator.h>

static void activate(void)
{
    printk(KERN_INFO POWER_TAG": Activated power class 2\n");
    set_backlight_level(BRIGHTNESS_P2);
    printk(KERN_INFO POWER_TAG": Start vibration setting\n");
    msm8974_pwm_vibrator_gain(VIBRATOR_P2);
    set_max_cpu_freq(MAX_CPUFREQ_P2);
    set_max_gpu_power_level(MAX_GPU_LV_P2);
    set_gov_powersave_bias(PS_BIAS_VLOW);
}

static void update(void){
    printk(KERN_INFO POWER_TAG": Update power class 2\n");
    set_backlight_level(BRIGHTNESS_P2);
}

const struct power_class_ops *POWER_OPS_2 = &((struct power_class_ops){ activate,update });
