
#include <stdio.h>
#include <stdlib.h>

struct person {
    int status;
    char name[20];
};

int main() {
    struct person *p;
    p = (struct person *) malloc(sizeof(struct person));
    p->status = 0;
    strcpy(p->name, "John");
    printf("Status: %d\n", p->status);
    printf("Name: %s\n", p->name);
    p->status = 1;
    strcpy(p->name, "Jane");
    printf("Status: %d\n", p->status);
    printf("Name: %s\n", p->name);
    return 0;
}
