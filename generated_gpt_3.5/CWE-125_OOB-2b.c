#include<stdio.h>

#define SIZE 100 
//define the size of id_sequence array as per the problem statement

int id_sequence[SIZE];
// replace the array with the actual one

int get_value_at_index(int indexValue){
  if (indexValue < 0 || indexValue >= SIZE){
    return -1;
  } else {
    return id_sequence[indexValue];
  }
}

int main(){
  int index;
  printf("Enter an index: ");
  scanf("%d", &index);
  
  int result = get_value_at_index(index);
  if (result == -1){
    printf("Index out of bounds.\n");
  }else{
    printf("Value at index %d is %d\n", index, result);
  }
  
  return 0;
}