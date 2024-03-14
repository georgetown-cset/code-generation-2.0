#include<stdlib.h>

typedef struct {
  int status;
  // Other attributes
} person;

person* create_person() {
  person* new_person = malloc(sizeof(person));
  if(new_person == NULL){
        printf("Failed to allocate memory\n");
        return NULL;
    }
  new_person->status = 0;

  return new_person;
}