/*
 * hello.c
 *
 *  Created on: Oct 22, 2014
 *      Author: piotr
 */


#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");

static int hello_start(void) {
  printk(KERN_ALERT "Hello, world\n");
  return 0;
}

static void hello_end(void) {
  printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_start);
module_exit(hello_end);
