#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024
#define CHARS_TO_COPY 100

int main() {
    // Allocate first large buffer, read from stdin 
    char *buf = (char*)malloc(SIZE * sizeof(char));
    if(buf == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }
    if(fgets(buf, CHARS_TO_COPY, stdin) == NULL){
        fprintf(stderr, "input error.\n");
        free(buf);
        return 1;
    }

    // Allocate second large buffer, read from stdin
    char *buf1 = (char*)malloc(SIZE * sizeof(char));
    if(buf1 == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        free(buf);
        return 1;
    }
    if(fgets(buf1, CHARS_TO_COPY, stdin) == NULL){
        fprintf(stderr, "input error.\n");
        free(buf);
        free(buf1);
        return 1;
    }

    // When you have done using the buffers, free the memory

    free(buf);
    free(buf1);

    return 0;
}