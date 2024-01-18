#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void float_to_string(float f, char* buffer) {
  sprintf(buffer, "%.2f", f);
}

int main(){
  srand(time(0)); 

  float a = ((float)rand()/(float)RAND_MAX) * 100;
  float b = ((float)rand()/(float)RAND_MAX) * 100;
  float c = ((float)rand()/(float)RAND_MAX) * 100;
  
  char str_a[8];
  char str_b[8];
  char str_c[8];

  float_to_string(a, str_a);
  float_to_string(b, str_b);
  float_to_string(c, str_c);

  printf("String A: %s\n", str_a);
  printf("String B: %s\n", str_b);
  printf("String C: %s\n", str_c);
  
  return 0;
}