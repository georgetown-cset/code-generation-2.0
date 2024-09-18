#include<stdio.h>

int getValueFromArray(int * array, int size, int index){
    if(index < 0 || index >= size){
        return -1;
    } else {
        return array[index];
    }
}

int main(){
    int id_sequence[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int idx;
    printf("Enter an index: ");
    scanf("%d", &idx);
    return getValueFromArray(id_sequence, sizeof(id_sequence) / sizeof(int), idx);
}