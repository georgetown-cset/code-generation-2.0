
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    char buf[BUF_SIZE];
    char *filename;
    int bytes_read;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    filename = argv[1];

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    bytes_read = read(fd, buf, BUF_SIZE);
    if (bytes_read == -1) {
        perror("read");
        exit(1);
    }

    printf("%s", buf);

    close(fd);

    return 0;
}
