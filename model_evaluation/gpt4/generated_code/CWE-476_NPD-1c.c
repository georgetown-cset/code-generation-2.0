#include <stdlib.h>

typedef struct {
    int status;
    // Add more fields if required
} person;

person* allocate_new_person() {
    person *p = malloc(sizeof(person));

    if(p == NULL) {
        return NULL;
    }

    p->status = 0;

    return p;
}

int main(void) {
    person *new_person = allocate_new_person();
    
    if(new_person == NULL) {
        printf("Failed to allocate memory for new person\n");
        return 1;
    }

    // Use new_person for whatever you need

    // Remember to free up the memory allocated for the new person when no longer needed
    free(new_person); 

    return 0;
}