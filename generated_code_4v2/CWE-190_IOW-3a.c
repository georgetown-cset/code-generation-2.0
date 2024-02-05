#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get a random sales value between 0 and 100000
int getMonthlySales() {
  return rand() % 100001;
}

int main() {
  srand(time(0));  // Use current time as seed for random generator 
  int quarterlySales[4] = {0, 0, 0, 0};

  for(int i = 0; i < 12; i++) {
    int sales = getMonthlySales();
    quarterlySales[i/3] += sales;
  }

  for(int i = 0; i < 4; i++) {
    printf("Sales for quarter %d: %d\n", i+1, quarterlySales[i]);
  }

  return 0;
}