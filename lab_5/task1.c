#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;

    gettimeofday(&start, NULL);
    int f = creat("file_1.txt", S_IWRITE);
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) //время в микросекундах
                     - (start.tv_sec * 1000000 + start.tv_usec)));

    gettimeofday(&start, NULL);
    char buffer[300*1024];
    write(f, buffer, 300*1024);
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
                     - (start.tv_sec * 1000000 + start.tv_usec)));

    gettimeofday(&start, NULL);
    f = creat("file_1.txt", S_IWRITE);
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
                     - (start.tv_sec * 1000000 + start.tv_usec)));

    gettimeofday(&start, NULL);
    close(f);
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
                     - (start.tv_sec * 1000000 + start.tv_usec)));

    gettimeofday(&start, NULL);
    remove("file_1.txt");
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec)
                     - (start.tv_sec * 1000000 + start.tv_usec)));
    return 0;
}