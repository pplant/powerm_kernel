#include <linux/kernel.h> 
#include <linux/platform_data/lm3630_bl.h>
#include <linux/cpufreq.h>
#include "include/powerm.h"

#include "include/powerm_control.h"

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
