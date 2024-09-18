#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int status;
    // add other members here
} person;

int main() {
    person *newPerson = (person*)malloc(sizeof(person));
    
    if (newPerson == NULL) {
        printf("Memory allocation failed");
        return 1;
    }
    
    newPerson->status = 0;
    
    // perform other operations with newPerson
    
    free(newPerson);
    
    return 0;
}