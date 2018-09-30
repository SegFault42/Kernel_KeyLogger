obj-m += keylogger.o
keylogger-objs := main.o lst.o misc.o log.o# file.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean

re: clean all

udev:
	sudo cp -fr ./key.rules /etc/udev/rules.d/key.rules
