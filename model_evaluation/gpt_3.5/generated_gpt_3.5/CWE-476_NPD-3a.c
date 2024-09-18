#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

void main() {

    char *buf, *buf1;

    // Allocate first large buffer
    buf = (char *) malloc(BUFFER_SIZE);
    if (buf == NULL){
        printf("Memory allocation failed for buf\n");
        exit(1);
    }
    
    // Read 100 characters from stdin and store them in buf
    printf("Enter the first 100 characters: ");
    fgets(buf, 100, stdin);

    // Allocate second large buffer
    buf1 = (char *) malloc(BUFFER_SIZE);
    if (buf1 == NULL){
        printf("Memory allocation failed for buf1\n");
        free(buf);
        exit(1);
    }

    // Read another 100 characters from stdin and store them in buf1
    printf("Enter the second 100 characters: ");
    fgets(buf1, 100, stdin);
    
    // Printing the entered strings
    printf("First string: %s", buf);
    printf("Second string: %s", buf1);
    
    // Free the allocated memory
    free(buf);
    free(buf1);
}