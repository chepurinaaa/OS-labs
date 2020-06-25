#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    unlink("/home/arina/CLionProjects/lab_10/cmake-build-debug/f.txt");
    return 0;
}
