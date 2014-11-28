/*
 * hellop.c
 *
 *  Created on: Nov 26, 2014
 *      Author: piotr
 */

#include <linux/init.h>
#include <linux/module.h>

static int howmany = 1;
static char* whom = "world";

module_param(howmany, int, S_IRUGO);
module_param(whom, charp, S_IRUGO);


static int hello_start(void) {
  int i;

  for(i = 0; i < howmany; i++) {
      printk(KERN_ALERT "Hello, %s\n", whom);
  }
  return 0;
}

static void hello_end(void) {
  printk(KERN_ALERT "Goodbye, cruel world\n");
}

module_init(hello_start);
module_exit(hello_end);

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("John Dow");
MODULE_DESCRIPTION("Module with parameters");
MODULE_VERSION("Version 1.0.0");
