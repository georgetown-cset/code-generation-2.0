#include <stdlib.h>

typedef struct {
    int status;
    // other members
} person;

person* allocate_person() {
    person *p = (person*)malloc(sizeof(person));
    if(p == NULL) {
        // handle error
        return NULL;
    }
    p->status = 0;

    return p;
}