#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024
#define INPUT_SIZE 100

int main() {
    char *buf  = (char *) malloc(BUFFER_SIZE);
    char *buf1 = (char *) malloc(BUFFER_SIZE);

    if (buf == NULL || buf1 == NULL) {
        printf("Memory not allocated.\n");
        return 1;   // exit the program if memory allocation failed
    }

    printf("Enter the first string of up to %d characters: ", INPUT_SIZE);
    fgets(buf, INPUT_SIZE, stdin);

    printf("Enter the second string of up to %d characters: ", INPUT_SIZE);
    fgets(buf1, INPUT_SIZE, stdin);

    // do something with buf and buf1
    
    free(buf);
    free(buf1);

    return 0;
}