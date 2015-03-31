VERSION = 3
PATCHLEVEL = 4
SUBLEVEL = 0
EXTRAVERSION = .1-energy-aware


obj-m := psupply.o
PWD := $(shell pwd)
KERNEL_DIR = $(PWD)/../msm
HOST_KDIR=/lib/modules/$(shell uname -r)/build
default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(PWD)/../arm-eabi-4.6/bin/arm-eabi- -C $(KERNEL_DIR) M=$(PWD) modules
host:
	$(MAKE) -C $(HOST_KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	$(MAKE) -C $(HOST_KDIR) M=$(PWD) clean
