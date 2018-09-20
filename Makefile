obj-m += keylogger.o
keylogger-objs := main.o lst.o misc.o log.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

re: clean all
