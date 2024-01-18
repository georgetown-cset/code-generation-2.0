#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define FILENAME "important_config"

void main()
{
    int file_descriptor;

    // Open file with specified flags and permissions
    file_descriptor = open(FILENAME, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);
    
    if (file_descriptor < 0) {
        // print an error message and exit if the file cannot be opened
        perror("Could not open file");
        return;
    }

    // Write something to the file
    if (write(file_descriptor, "content", 7) != 7) {
        // print an error message and exit if write operation is unsuccessful 
        perror("Could not write to file");
    }
    // Close the file
    close(file_descriptor);
}