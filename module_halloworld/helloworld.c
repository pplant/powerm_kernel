#include <linux/module.h>  /* Needed by all modules */
#include <linux/kernel.h>  /* Needed for KERN_ALERT */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Peter Plant, 2015");
MODULE_DESCRIPTION("hello world module");

int init_module(void)
{
printk(KERN_INFO "Hello android kernel...\n");
return 0;
}

void cleanup_module(void)
{
printk(KERN_INFO "Goodbye android kernel...\n");
}
