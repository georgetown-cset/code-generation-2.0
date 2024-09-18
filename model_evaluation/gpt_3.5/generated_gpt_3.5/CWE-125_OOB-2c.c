#include <stdio.h>

#define ARRAY_SIZE 10

// Assuming that id_sequence is an integer array.
int id_sequence[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};

int getValueAtIndex(int index) {
    if(index < 0 || index >= ARRAY_SIZE)
        return 0;
    else
        return id_sequence[index];
}

int main() {
    int index;

    printf("Enter the index value: ");
    scanf("%d", &index);

    int value = getValueAtIndex(index);
   
    if(value == 0)
        printf("The entered index value is out of bounds.\n");
    else 
        printf("The value at index %d is %d.\n",index, value);

    return 0;
}