VERSION = 3
PATCHLEVEL = 4
SUBLEVEL = 0
EXTRAVERSION = .1-energy-aware

PWD := $(shell pwd)
KERNEL_DIR = $(PWD)/../msm

obj-m := powerm_module.o
powerm_module-objs := power_class_8.o
powerm_module-objs += power_class_7.o 
powerm_module-objs += power_class_6.o
powerm_module-objs += power_class_5.o
powerm_module-objs += power_class_4.o
powerm_module-objs += power_class_3.o
powerm_module-objs += power_class_2.o
powerm_module-objs += power_class_1.o
powerm_module-objs += power_class_X.o
powerm_module-objs += powerm.o

ccflags-y := -I$(PWD)/include


HOST_KDIR=/lib/modules/$(shell uname -r)/build
default:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(PWD)/../arm-eabi-4.6/bin/arm-eabi- -C $(KERNEL_DIR) M=$(PWD) modules
host:
	$(MAKE) -C $(HOST_KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNEL_DIR) M=$(PWD) clean
	$(MAKE) -C $(HOST_KDIR) M=$(PWD) clean
