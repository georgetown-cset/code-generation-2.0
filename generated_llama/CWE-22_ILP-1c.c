
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_FILE_SIZE 1024

int main(int argc, char *argv[])
{
    int fd;
    char buffer[MAX_FILE_SIZE];
    char *filename;
    int i;

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

    i = read(fd, buffer, MAX_FILE_SIZE);
    if (i == -1) {
        perror("read");
        exit(1);
    }

    printf("Read %d bytes from %s\n", i, filename);
    printf("Buffer contains: %s\n", buffer);

    close(fd);

    return 0;
}
