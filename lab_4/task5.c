#include <stdio.h>
#include <stdlib.h>

int main () {
    int n = 100;
    int* buffer = (int*) malloc(sizeof(int)*n);
    buffer[n] = 0;
    return 0;
}


