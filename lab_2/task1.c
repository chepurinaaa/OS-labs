#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    //printf("hello world (pid:%d)\n", (int) getpid());
    int x = 100;
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello from child, x = %d\n", x);
        x++;
        printf("hello from child, new x = %d\n", x);
    } else {
        printf("hello from parent, x = %d\n", x);
        x--;
        printf("hello from parent, new x = %d\n", x);
    }
    return 0;
}