# To build modules outside of the kernel tree, we run "make"
# in the kernel source tree; the Makefile these then includes this
# Makefile once again.
# This conditional selects whether we are being included from the
# kernel Makefile or not.
ifeq ($(KERNELRELEASE),)

    # Assume the source tree is where the running kernel was built
    # You should set KERNELDIR in the environment if it's elsewhere
    #KERNELDIR ?= /lib/modules/$(shell uname -r)/build
    KERNELDIR := $(SDKTARGETSYSROOT)/usr/src/kernel
    # The current directory is passed to sub-makes as argument
    PWD := $(shell pwd)

all:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean
	#rm -rf *.o *~ core .depend .*.cmd *.ko *.mod.c .tmp_versions

else
    # called from kernel build system: just declare what our modules are
    obj-m := hello.o 
endif


