#include <stdio.h>
#include <stdlib.h>

int main () {
    int n = 100;
    int* buffer = (int*) malloc(sizeof(int)*n);
    free(buffer);
    printf("%d", buffer[n-1]);
    return 0;
}