obj-m	:=rqst_gpio.o
KDIR 	:=/home/paul/RP3_PROJECT/linux4_19_97
MYCC	=/home/paul/opt/gcc-raspberry-pi/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-

# The KDIR must have to assign a ./direction
modules:
	$(MAKE) ARCH=arm CROSS_COMPILE=$(MYCC) -C $(KDIR) SUBDIRS=$(shell pwd) modules
user:
	$(MYCC)gcc -Wall -o user_test user_test.c
clean:
	rm -f modules.order Module.symvers  *.o *.ko *.mod.c .*.o .*.ko
