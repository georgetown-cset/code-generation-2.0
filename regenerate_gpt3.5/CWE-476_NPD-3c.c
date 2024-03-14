#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf = (char *) malloc(1024 * sizeof(char));
    
    if(buf == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return -1;
    }
    
    printf("Enter up to 10 characters: ");
    fgets(buf, 10, stdin);
    
    printf("Characters stored in buf: %s\n", buf);
    
    free(buf);
    return 0;
}