#include <stdio.h>
#include <sys/stat.h>

int main() {
    FILE* f1 = fopen("f.txt", "r");
    struct stat info;
    stat("f.txt", &info);
    printf("st_nlink = %lu name = %s\n", info.st_nlink, "f.txt");
    char symb = 0;
    do{
        while ((symb = fgetc(f1)) != EOF) {
            printf("%c", symb);
        }
        fseek(f1, 0, SEEK_SET);
    } while (1);
    return 0;
}
