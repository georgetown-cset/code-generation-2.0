#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf;
    buf = (char *)malloc(1024 * sizeof(char));

    if (buf == NULL) {
        printf("Memory allocation failed\n");
        return -1;
    }

    printf("Enter a string: \n");
    fgets(buf, 10, stdin);

    printf("You entered: %s\n", buf);

    free(buf);

    return 0;
}