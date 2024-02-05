#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    if(argc < 3){
        printf("Insufficient command line arguments.\n");
        return 0;
    }

    int index = atoi(argv[1]);
    if(index >= argc || index < 0){
        printf("Invalid Index.\n");
        return 0;
    }

    printf("%s\n", argv[index]);
    return 0;
}