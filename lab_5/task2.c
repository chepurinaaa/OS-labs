#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;

    gettimeofday(&start, NULL);
    int f = creat("file_1.txt", S_IWRITE);
    char buffer[1];
    int i;
    for (i = 0; i < 300*1000; i++) {
        write(f, buffer, 1);
    }
    close(f);
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) //время в микросекундах
                     - (start.tv_sec * 1000000 + start.tv_usec)));


    gettimeofday(&start, NULL);
    FILE* f2;
    f2 = fopen("file_2.txt", "w");
    char buffer_2[1];
    for (i = 0; i < 300*1000; i++) {
        fwrite(buffer_2, 1, 1, f2);
    }
    fclose(f2);
    gettimeofday(&end, NULL);
    printf("%ld\n", ((end.tv_sec * 1000000 + end.tv_usec) //время в микросекундах
                     - (start.tv_sec * 1000000 + start.tv_usec)));
}