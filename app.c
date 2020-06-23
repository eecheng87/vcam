#include "app.h"

void init()
{
    /* query capability */
    if (-1 == ioctl(fd, VIDIOC_QUERYCAP, &caps)) {
        perror("Querying Capabilities");
        return;
    }
}
int main()
{
    /* O_NONBLOCK is option */
    fd = open("/dev/video1", O_RDWR);
    if (fd == -1) {
        perror("Opening video device");
        return 1;
    }

    /* defualt io method is mmap */
    init();
    close(fd);
    return 0;
}