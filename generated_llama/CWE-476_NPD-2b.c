
#include <stdio.h>
#include <stdlib.h>

struct person {
    int status;
    char *name;
};

int main(void) {
    struct person *p = malloc(sizeof(struct person));
    p->status = 0;
    p->name = "John";
    printf("%d\n", p->status);
    printf("%s\n", p->name);
    p->status = 1;
    p->name = "Jane";
    printf("%d\n", p->status);
    printf("%s\n", p->name);
    return 0;
}
