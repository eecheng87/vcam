#include "app.h"

int print_caps(int fd)
{
        struct v4l2_capability caps = {};
        if (-1 == ioctl(fd, VIDIOC_QUERYCAP, &caps))
        {
                perror("Querying Capabilities");
                return 1;
        }

        printf( "Driver Caps:\n"
                "  Driver: \"%s\"\n"
                "  Card: \"%s\"\n"
                "  Bus: \"%s\"\n"
                "  Version: %d.%d\n"
                "  Capabilities: %08x\n",
                caps.driver,
                caps.card,
                caps.bus_info,
                (caps.version>>16)&&0xff,
                (caps.version>>24)&&0xff,
                caps.capabilities);

    return 0;
}
int main(){

    int fd;
    fd = open("/dev/video1", O_RDWR);
    if (fd == -1)
    {
            perror("Opening video device");
            return 1;
    }
    if(print_caps(fd))
            return 1;
    return 0;
}