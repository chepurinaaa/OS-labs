#include <stdio.h>
#include <malloc.h>
#include <time.h>

int main() {
    size_t size = 10000;
    //scanf("%d", &size);
    char* ptr = (char*)malloc(size*2048);
    if (!ptr) {
        return 1;
    }
    int i = 0;
    int s = 0;
    //scanf("%d", &s);
    clock_t t1;
    t1 = clock()/CLOCKS_PER_SEC;
    while (1){
        ptr[i] = "a";
        if (s == 0){
            continue;
        } else {
            if ((clock()/CLOCKS_PER_SEC - t1) >= s) {
                break;
            }
        }
    }
    return 0;
}
