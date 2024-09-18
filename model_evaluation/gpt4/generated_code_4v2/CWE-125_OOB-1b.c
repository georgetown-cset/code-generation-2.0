#include <stdio.h>

int getValueFromArray(int array[], int size, int index) {
    if(index < size && index >= 0){
        return array[index];
    } else {
        return -1;
    }
}

int main() {
    int id_sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);
    int index;
    scanf("%d", &index);
    int returnVal = getValueFromArray(id_sequence, size, index);
    return returnVal;
}