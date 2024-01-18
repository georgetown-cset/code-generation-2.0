#include <stdio.h>

int id_sequence[100]; // You can change the size of the array according to your needs

int getValueAtIndex() {
    int index;
    printf("Enter the index value: ");
    scanf("%d", &index);
    
    if(index >= 0 && index < sizeof(id_sequence) / sizeof(id_sequence[0])) {
        return id_sequence[index];
    } 
    else {
        return 0;
    }
}

int main() {
  
    // We are populating the array for demonstration purposes
    for(int i = 0; i < sizeof(id_sequence) / sizeof(id_sequence[0]); i++) {
        id_sequence[i] = i + 1;
    }
    
    int value = getValueAtIndex();

    printf("Value at given index is: %d\n", value);
    
    return 0;
}