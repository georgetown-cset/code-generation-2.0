#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int fileDescriptor;

    fileDescriptor = open("filename.txt", O_CREAT | O_TRUNC | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);

    if (fileDescriptor == -1) {
        printf("Failed to open or create file \n");
    } else {
        printf("File is opened or created successfully \n");
    }

    return 0;
}