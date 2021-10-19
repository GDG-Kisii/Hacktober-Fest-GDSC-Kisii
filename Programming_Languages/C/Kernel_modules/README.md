## Makefile should be modified depending on the driver that you are running

example

obj-m += module_name.o

all:

         make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
        make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
