#include <stdio.h>

// Given array for demonstration purpose
int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int size = sizeof(array)/sizeof(array[0]);

int getArrayElement(int index) {
    if (index < 0 || index >= size) {
        return -1;
    } else {
        return array[index];
    }
}

int main() {
    int index = 5;
    printf("The value at index %d is %d\n", index, getArrayElement(index));
    
    index = 10;
    printf("The value at index %d is %d", index, getArrayElement(index));
    
    return 0;
}