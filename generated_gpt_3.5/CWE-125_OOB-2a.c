#include <stdio.h>

#define MAX_SIZE 100
int id_sequence[MAX_SIZE];  // Note: the array should be initialised with desired values

int getValueAtIndex(int index){
  if(index >= MAX_SIZE || index < 0){
    return -1;
  }
  else{
    return id_sequence[index];
  }
}

int main(){
  int index;
  printf("Enter an index value: ");
  scanf("%d", &index);

  int retVal = getValueAtIndex(index);
  if (retVal == -1){
    printf("Index is out of bounds.\n");
  }
  else{
    printf("The value at index %d is %d.\n", index, retVal);
  }
  
  return 0;
}