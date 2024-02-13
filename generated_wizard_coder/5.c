#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <integer>\n", argv[0]);
        return 1;
    }

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int num = atoi(argv[1]);

    if (num >= 0 && num < size) {
        printf("Element at index %d: %d\n", num, arr[num]);
    } else {
        printf("invalid input\n");
    }

    return 0;
}