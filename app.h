#ifndef APP_H
#define APP_H
#include <errno.h>
#include <fcntl.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
//#include <linux/time.h>
#include "vcam.h"
#include "vdev2.h"

/* video file descriptor */
int fd;
struct v4l2_capability caps = {};

void init();

#endif