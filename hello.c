/*
 * hello.c
 *
 *  Created on: Oct 22, 2014
 *      Author: piotr
 */


#include <linux/init.h>
#include <linux/module.h>

static int hello_start(void) {
  printk(KERN_ALERT "Hello, world\n");
  return 0;
}

static void hello_end(void) {
  printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_start);
module_exit(hello_end);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("John Dow");
MODULE_DESCRIPTION("My first kernel module.");
MODULE_VERSION("Version 1.0.1");

// Use modinfo to read the above information from hello.ko
