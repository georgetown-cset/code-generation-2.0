#include <stdio.h>

int main() {
    FILE *file;
    char fileName[] = "safe_directory/fileName"; /* replace with your file name */
    char ch;

    /* Open file in read mode */
    file = fopen(fileName, "r");

    /* Error handling for file opening */
    if(file == NULL){
        printf("File cannot be opened \n");
        return 0;
    }

    /* Reading the file character by character */
    printf("Content of the file is: \n");
    ch = fgetc(file);
    while (ch != EOF)
    {
        /* print each character */
        putchar(ch);
        ch = fgetc(file);
    }

    /* Close the file */
    fclose(file);

    return 0;
}