#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/platform_data/lm3630_bl.h>
#include <linux/cpufreq.h>
#include <linux/msm_kgsl.h>
#include "include/powerm.h"

#include "include/powerm_control.h"

#include "kgsl.h"
#include "kgsl_pwrctrl.h"
#include "kgsl_device.h"

void set_backlight_level(int level)
{
	int level_current = 255;
	level_current = lm3630_lcd_backlight_get_level();
	printk(KERN_INFO POWER_TAG": Level current %d\n",level_current);
	if(level_current > level){
		lm3630_lcd_backlight_set_level(level);
		printk(KERN_INFO POWER_TAG": New current level %d\n",level);
	}

	lm3630_lcd_backlight_set_max_level(level);
}

void set_gov_powersave_bias(int bias)
{

	if(update_powersave_bias(bias))
	{
		printk(KERN_INFO "bias updated %d\n",bias);
	}
	else
	{
		printk(KERN_INFO "bias still the same %d\n",bias);
	}

	/*dbs_tuners_ins.powersave_bias = bias;*/
}

void set_max_cpu_freq(int max_freq)
{
	int cpu;

	for_each_online_cpu(cpu) {
		struct cpufreq_policy *policy = cpufreq_cpu_get(cpu);
		if (!policy)
			continue;
		policy->max = max_freq;
		policy->cpuinfo.max_freq = max_freq;
		policy->user_policy.max = max_freq;
		cpufreq_cpu_put(policy);
	}
}

void set_max_gpu_power_level(int max_level){
	struct kgsl_device *device = kgsl_get_device(KGSL_DEVICE_3D0);
	struct kgsl_pwrctrl *pwr = &device->pwrctrl;
	int active = pwr->active_pwrlevel;
	pwr->max_pwrlevel = 5;
	printk(KERN_INFO "Active 3D0 pwrlevel:%d",active);
}
