#include <stdio.h>

// Assume we have an array of size 10 for this example
#define SIZE 10

int value_at_index(int arr[], int index){
    if(index < 0 || index >= SIZE){
        return -1;
    }
    return arr[index];
}

int main() {
    int i, index;
    int arr[SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        
    printf("Enter the index: ");
    scanf("%d", &index);
    int value = value_at_index(arr, index);
    
    if(value == -1){
        printf("Index out of bounds.");
    } else {
        printf("The value at index %d is: %d", index, value);
    }
    return 0;
}