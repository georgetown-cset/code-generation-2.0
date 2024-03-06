
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    int fd;
    char important_config_data[] = "important_config_data";

    fd = open("important_config", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    write(fd, important_config_data, sizeof(important_config_data));

    close(fd);

    return 0;
}
