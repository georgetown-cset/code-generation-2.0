
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc <= 1 || argc > 2 || argv[1] == NULL) {
        printf("Usage: ./argv_index <index>\n");
        return 1;
    }

    int index = atoi(argv[1]);

    if (index < 1 || index > argc) {
        printf("Invalid index. Index should be between 1 and the number of arguments.\n");
        return 1;
    }

    printf("Argument %d: %s\n", index, argv[index]);

    return 0;
}