#include <stdio.h>

#define ARRAY_SIZE 10

int getArrayValue(int arr[ARRAY_SIZE], int index) {
    if (index<0 || index>=ARRAY_SIZE){
        return -1;
    }
    else{
        return arr[index];
    }
}

int main() {
    int arr[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    int index;

    printf("Please enter an index: ");
    scanf("%d", &index);
    
    int value = getArrayValue(arr, index);
    if (value == -1){
        printf("Index is out of bounds.\n");
    }
    else{
        printf("Value at index %d is %d\n", index, value);
    }

    return 0;
}