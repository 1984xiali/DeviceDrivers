#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/stat.h>
#include <linux/moduleparam.h>

#define DRIVER_AUTHOR "Jeff Li"
#define LICENSE_DESC "Dual BSD/GPL"
#define DRIVER_DESC "This is a Hello World Module for Demo purpose"

MODULE_DESCRIPTION(DRIVER_DESC);
MODULE_LICENSE(LICENSE_DESC);
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_SUPPORTED_DEVICE("UBUNTU 12.04 been tested");

static char* whom = "world";
static int howmany = 1;

static int __init hello_init(void)
{
	printk(KERN_ALERT "Hello, world, from KERN_ALERT\n");
	printk(KERN_INFO "Hello, world, from KERN_INFO\n");
	return 0;
}

static void __exit hello_exit(void)
{
	printk(KERN_ALERT "Byebye, cruel world\n");
}

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);
module_init(hello_init);
module_exit(hello_exit);
