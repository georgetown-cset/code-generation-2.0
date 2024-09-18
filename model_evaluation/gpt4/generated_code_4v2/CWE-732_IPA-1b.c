#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    int file_descriptor;
    char* string = "important_config";

    /* Opening the file with the mentioned flags */
    file_descriptor = open("important_config", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

    if(file_descriptor < 0) {
        /* File opening failed */
        perror("Error in opening file");
        return 1;
    }

    /* Writing the string to the file */
    if(write(file_descriptor, string, sizeof(string)) != sizeof(string)) {
        /* Write operation failed */
        perror("Error in writing to file");
        return 1;
    }
    
    /* Closing the file */
    if(close(file_descriptor) < 0) {
        /* File closing failed */
        perror("Error in closing file");
        return 1;
    }

    return 0;
}