
#include <stdio.h>
#include <stdlib.h>

struct person {
    int status;
};

int main(void) {
    struct person *p = (struct person *) malloc(sizeof(struct person));
    p->status = 0;
    printf("%d\n", p->status);
    return 0;
}
