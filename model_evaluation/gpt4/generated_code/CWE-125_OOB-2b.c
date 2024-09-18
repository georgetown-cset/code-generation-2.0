#include <stdio.h>

// Assuming global variable id_sequence
int id_sequence[10]; // change this array as necessary

// The function
int getValueAtIndex(int index){
    // Checking if the index value is in bounds
    if(index < 0 || index >= sizeof(id_sequence)/sizeof(id_sequence[0])){
        return -1;
    }

    // If the index value is in bounds return the value 
    return id_sequence[index];
}

int main(){
    int index;
    // Prompt the user for an index value
    printf("Enter an index value: ");
    scanf("%d", &index);
    
    // Get value at index 
    int result = getValueAtIndex(index);

    // Check result
    if (result == -1){
        printf("Index out of bounds\n");
    }
    else{
        printf("The value at index %d is %d\n", index, result);
    }

    return 0;
}