
#include <stdio.h>
#include <stdlib.h>

struct person {
    int age;
    char name[20];
    int status;
};

int main() {
    struct person *p;
    p = (struct person *) malloc(sizeof(struct person));
    p->status = 0;
    return 0;
}
