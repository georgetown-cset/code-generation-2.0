#include <stdlib.h>

typedef struct {
    int status;
} Person;

Person* new_person(){
    Person* person = (Person*)malloc(sizeof(Person));
    if(person == NULL){
       // Handle error here (such as printing error message and exiting program)
       fprintf(stderr, "Memory allocation failed!\n");
       exit(1);
    }
    person->status = 0;
    return person;
}