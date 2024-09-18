#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main() {
    char *filename = "important_config";
    char *config_string = "important_config";
    int fd;

    fd = open(filename, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    if(write(fd, config_string, strlen(config_string)) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    close(fd);

    return 0;
}