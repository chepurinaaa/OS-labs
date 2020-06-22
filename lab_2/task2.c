#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void write_message() {
    printf("goodbye from parent\n");
}

int main(int argc, char *argv[]) {
    //printf("hello world (pid:%d)\n", (int) getpid());
    auto id = getpid();
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello from child\n");
        kill(id, SIGCHLD);
    } else {
        signal(SIGCHLD, write_message);
        pause();
    }
    return 0;
}
