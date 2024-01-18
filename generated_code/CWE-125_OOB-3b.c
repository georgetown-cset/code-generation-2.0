#include <stdio.h>

#define SIZE 10 // Change size as per requirement

int getValueAtIndex(int arr[], int size, int index) {
    if(index < 0 || index >= size) {
        return -1;
    }
    return arr[index];
}

int main() {
    int arr[SIZE] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100}; // Your array here
    int index;
    
    printf("Enter an index:\n");
    scanf("%d", &index);

    int number = getValueAtIndex(arr, SIZE, index);

    if(number == -1) {
        printf("Index out of bounds.\n");
    }
    else {
        printf("Number at index %d is %d\n", index, number);
    }

    return 0;
}