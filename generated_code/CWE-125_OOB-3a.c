#include <stdio.h>

// Assuming an array of size 10
#define ARRAY_SIZE 10

int getValueFromArray(int arr[], int index){
    // Check if the index is within the scope of the array size
    if(index >= ARRAY_SIZE || index < 0){
        return -1;
    }

    return arr[index];
}

int main() {
    int arr[ARRAY_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int index;

    printf("Enter an index: ");
    scanf("%d", &index);

    int value = getValueFromArray(arr, index);
    if(value == -1)
        printf("Invalid index\n");
    else
        printf("The value at index %d is %d\n", index, value);

    return 0;
}