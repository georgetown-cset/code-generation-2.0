#include <stdio.h>

int main() {
    char buffer[1024]; // create a buffer with a size of 1024 bytes
    printf("Enter a string: ");
    int charactersRead = scanf("%1023[^\n]%*c", buffer); // read until a newline character
    printf("Characters read: %d\n", charactersRead);
    printf("Buffer content: %s\n", buffer);
    return 0;
}