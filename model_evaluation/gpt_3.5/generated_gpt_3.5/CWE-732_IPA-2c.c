#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

const char *important_config = "your important content goes here";

int main() {
    /* Open the file for reading and writing, create it if it doesn't exist */
    int fd = open("config_file", O_RDWR | O_CREAT, S_IRWXU);

    if (fd == -1) {
        /* Handle error */
        return -1;
    }

    /* Write the important configuration to the file */
    if (write(fd, important_config, sizeof(important_config)) == -1) {
        /* Handle error */
        return -1;
    }

    /* Close the file descriptor */
    if (close(fd) == -1) {
        /* Handle error */
        return -1;
    }

    return 0;
}