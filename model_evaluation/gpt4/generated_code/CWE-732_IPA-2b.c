#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // define the file path
    const char* filepath = "/path/to/your/file.txt";

    // create/open the file using the defined flags
    int file_descriptor = open(filepath, O_CREAT | O_TRUNC | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);

    // check whether file is opened successfully
    if(file_descriptor < 0) {
        perror("Error opening file");
        return 1;
    } 
    else {
        printf("File opened successfully with fd %d\n", file_descriptor);

        // Your code to write to the file goes here.

        //close the file
        if(close(file_descriptor) < 0) {
            perror("Error closing file");
            return 1;
        } else {
            printf("File %s closed successfully. \n", filepath);
        }
    }

    return 0;
}