#include <stdio.h>

// function getValueFromArray
int getValueFromArray(int* arr, int size, int index) {
    if (index >= 0 && index < size) {
        return arr[index];
    } else {
        return -1;
    }
}

// main function
int main() {
    int id_sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // You can use different values
    int size = sizeof(id_sequence)/sizeof(id_sequence[0]);
    int index;
    
    printf("Enter an index: ");
    scanf("%d", &index);

    int value = getValueFromArray(id_sequence, size, index);
    
    return value;
}