#include <stdlib.h>

typedef struct {
    int status;
    // ... other fields ...
} person;

person* new_person() {
    // Allocating memory
    person* p = (person*)malloc(sizeof(person));

    // Checking if memory allocation was successful
    if(p == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // Setting the status field to 0
    p->status = 0;

    return p;
}

int main() {
    person* p = new_person();
    // ... use p ...
    // Remember to free the allocated memory
    free(p);

    return 0;
}