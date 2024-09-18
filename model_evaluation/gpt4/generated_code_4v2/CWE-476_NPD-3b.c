#include <stdio.h>

int main() {
    char buffer[1024];
    int characters_read;

    printf("Enter a string: ");
    characters_read = scanf("%1023[^\n]%*c", buffer);
    
    if (characters_read > 0) {
        /* your logic here; for now just print number of characters read */
        printf("Number of characters read: %d\n", characters_read);
    } else {
        printf("No characters read or some error occurred.\n");
    }

    return 0;
}