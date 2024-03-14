#include <stdio.h>
#include <stdlib.h>

int main() {
    char *buf = (char *)malloc(1024);

    if(buf == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fgets(buf, 10, stdin);

    printf("Input stored in buffer: %s\n", buf);

    free(buf);

    return 0;
}