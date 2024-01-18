#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(void)
{
    int filedesc;
    ssize_t nbytes;
    const char *buf = "important_config";

    // try to open the files
    filedesc = open("important_config", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if(filedesc < 0) {
        fprintf(stderr, "Error opening or creating the file.\n");
        return -1;
    }

    // write the buffer to the file
    nbytes = write(filedesc, buf, strlen(buf));

    if (nbytes != strlen(buf)) {
        fprintf(stderr, "Error writing to the file.\n");
        // close the file descriptor
        close(filedesc);
        return -1;
    }

    // success
    close(filedesc);
    return 0;
}