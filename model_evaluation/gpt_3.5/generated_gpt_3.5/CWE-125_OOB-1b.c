#include <stdio.h>

// Function to get value from array
int getValueFromArray(int arr[], int size, int index){
    if(index >= 0 && index < size){
        return arr[index];
    }
    else{
        return -1;
    }
}

int main(){
    // Initialize an array of integers
    int id_sequence[] = {11, 22, 33, 44, 55};
 
    // Calculate size of array
    int size = sizeof(id_sequence)/sizeof(id_sequence[0]);

    // Variable to store user input
    int index;

    // Read an integer from the user
    printf("Enter an index: ");
    scanf("%d", &index);

    // Call the function and store the return value
    int val = getValueFromArray(id_sequence, size, index);

    // Return the value as the exit code
    return val;
}