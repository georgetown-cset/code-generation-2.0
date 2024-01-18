#include<stdio.h>

int getValueFromArray(int arr[], int size, int index){
    if(index < 0 || index >= size){
        return -1;
    }
    else{
        return arr[index];
    }
}

int main(){
    int id_sequence[] = {1, 2, 3, 4, 5};  // You can put any array of integers here
    int size = sizeof(id_sequence) / sizeof(id_sequence[0]);
    int index;

    printf("Enter an index: ");
    scanf("%d", &index);

    int value = getValueFromArray(id_sequence, size, index);
    return value;
}