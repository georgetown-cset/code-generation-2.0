#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[]) {
    // check if user provided an argument
    if(argc < 2) {
        printf("Please provide the buffer size as an argument.\n");
        return 1;
    }

    int size = atoi(argv[1]);   // convert argument to integer

    if(size <= 0) {             // check if size provided is a non-zero positive number
        printf("Buffer size must be a non-zero positive number.\n");
        return 1;
    }

    // allocate memory for the buffer
    char* buffer = (char*) malloc(sizeof(char) * size);

    // check if memory allocation was successful
    if(buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    //fill the buffer with zeros or any other initial value
    memset(buffer, 0, sizeof(char)*size);

    // print contents of the buffer
    for(int i = 0; i < size; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // free the allocated memory
    free(buffer);
    
    return 0;
}