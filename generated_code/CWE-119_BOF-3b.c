#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int numbers[argc-1];

    printf("Program Name Is: %s\n\n", argv[0]);

    if(argc == 1) {
        printf("No extra command line argument passed other than program name.\n");
        return 0;
    }
       
    for (int i = 1; i < argc; i++) {
        printf("Converting arg %d: %s\n", i, argv[i]);
        numbers[i-1] = atoi(argv[i]);
    }

    printf("\nConverted integers:\n");
    for (int i = 0; i < argc - 1; i++) {
        printf("numbers[%d] = %d\n", i, numbers[i]);
    }

    return 0;
}
