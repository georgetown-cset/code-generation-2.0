#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 1024

int scan(char *buffer) {
    int ch, count = 0;
    
    do {
        ch = fgetc(stdin);
        if (ch == EOF || count >= BUFFER_SIZE - 1) {
            // Early return if EOF or buffer size limit is reached
            if (ch == EOF) {
                return count;
            } else {
                ungetc(ch, stdin);
                return -1;
            }
        }
        buffer[count++] = (char)ch;
    } while (ch != '\n');

    buffer[count] = '\0'; // Null-terminate the string
    return count;
}

int main() {
    char buffer[BUFFER_SIZE];
    int n;

    n = scan(buffer);
    if (n > 0) {
        printf("Read %d characters: %s\n", n, buffer);
    } else if (n == -1) {
        perror("Error reading input");
    }

    return 0;
}