#include <stdio.h>
#include <stdlib.h>

int main () {
    int* p;
    p = NULL;
    int star = *p;
    printf("%d", star);
    return 0;
}

