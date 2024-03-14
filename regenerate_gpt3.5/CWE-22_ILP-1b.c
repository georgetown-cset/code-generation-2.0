#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char filename[100];
    char path[100] = "/safe/";

    printf("Enter the name of the file you want to read: ");
    scanf("%s", filename);

    strcat(path, filename);

    file = fopen(path, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    char c;
    while ((c = fgetc(file)) != EOF) {
        printf("%c", c);
    }

    fclose(file);

    return 0;
}