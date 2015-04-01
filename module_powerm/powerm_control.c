#include <linux/kernel.h> 
#include <linux/platform_data/lm3630_bl.h>

#include "include/powerm_control.h"

void set_backlight_level(int level){
	int level_current = 255;
	level_current = lm3630_lcd_backlight_get_level();
	if(level_current < level){
		lm3630_lcd_backlight_set_level(level);
		printk(KERN_INFO POWER_TAG"Level current %d\n",level_current);
	}

	level_current = lm3630_lcd_backlight_get_level();

}