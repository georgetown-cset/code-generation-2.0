
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd;
    char important_config[] = "important_config";

    fd = open("important_config", O_RDWR | O_CREAT, 0700);
    write(fd, important_config, sizeof(important_config));
    close(fd);

    return 0;
}
