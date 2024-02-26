#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    const char *filename = "important_config";
    char *data = "important_config\n"; // the string to be written
    int file_fd;
    umask(0); // set the umask to 0 for this example, to achieve the desired file permissions

    file_fd = open(filename, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    if (file_fd < 0) {
        perror("open");
        return 1;
    }

    if (write(file_fd, data, strlen(data) + 1) < 0) {
        perror("write");
        close(file_fd);
        return 1;
    }

    close(file_fd);
    printf("Data written to file %s successfully.\n", filename);

    return 0;
}