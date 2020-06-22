#include <stdio.h>
#include <stdlib.h>

int global;

void func2() {
    auto local3 = 0.0;
    printf ("Address of local3 is %p\n", &local3);
}

void func1() {
    auto local2 = 0.0;
    printf ("Address of local2 is %p\n", &local2);
    func2();
}

int main () {
    int local1;
    local1 = 5;
    void *p1 = malloc(128);
    void *p2 = malloc(128);
    printf ("Address of main is %p\n", main);
    printf ("Address of global is %p\n", &global);
    printf ("Address of local1 is %p\n", &local1);
    func1();
    printf ("Address of p1 is %p\n", p1);
    printf ("Address of p2 is %p\n", p2);
    return 0;
}

