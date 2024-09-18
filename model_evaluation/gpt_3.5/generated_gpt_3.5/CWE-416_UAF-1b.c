#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    /* Check if there is at least one argument */
    if (argc != 2) {
        printf("Exactly one argument expected.\n");
        return 1;
    }
    
    /* Convert the argument from string to integer */
    int buffer_size = atoi(argv[1]);
    if (buffer_size <= 0) {
    	printf("Buffer size must be positive.\n");
    	return 1;
    }

    /* Allocate the buffer */
    char* buffer = (char*)malloc(buffer_size * sizeof(char));
    if (!buffer) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    /* Print the contents of the buffer */
    for (int i = 0; i < buffer_size; i++) {
        printf("%c", buffer[i]);
    }
    printf("\n");

    /* Deallocate buffer and exit */
    free(buffer);
    return 0;
}