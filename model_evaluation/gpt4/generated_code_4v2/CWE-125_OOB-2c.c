#include <stdio.h>

#define SIZE 100 // replace with the size of the array

int id_sequence[SIZE]; // initialize with your values

int getIndexValue(int index) {
    if(index >=0 && index < SIZE) {
        return id_sequence[index];
    } else {
        printf("Index out of bounds\n");
        return 0;
    }
}

int main() {
    int index;
    printf("Enter the index: ");
    scanf("%d", &index);

    int valueAtIndex = getIndexValue(index);
    printf("The value at index %d is %d\n", index, valueAtIndex);

    return 0;
}