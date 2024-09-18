#include <stdio.h>

int getIndexValue(int index) {
    int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Example array, modify it for your use case

    if (index < 0 || index > 9) {
        return -1;
    } else {
        return array[index];
    }
}

int main() {
    int index;
    printf("Enter an index: ");
    scanf("%d",&index);

    int result = getIndexValue(index);
    printf("The value at index %d is: %d\n", index, result);
    return 0;
}