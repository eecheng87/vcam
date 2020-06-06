target = vcam
vcam-objs = module.o control.o device.o videobuf.o fb.o
obj-m = $(target).o

CFLAGS_utils = -O2 -Wall -Wextra -pedantic -std=c99
CFLAGS_app = -O2 -Wall -Wextra -std=c99

.PHONY: all
all: kmod vcam-util app

vcam-util: vcam-util.c vcam.h
	$(CC) $(CFLAGS_utils) -o $@ $<

app: app.c app.h vcam.h
	$(CC) $(CFLAGS_app) -o $@ $<


kmod:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

.PHONY: clean
clean:
	$(MAKE) -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	$(RM) vcam-util

load:
	sudo insmod $(target).ko

unload:
	sudo rmmod $(target) || true >/dev/null

reload:
	$(MAKE) unload
	$(MAKE) load