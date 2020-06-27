#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    FILE* f2;
    int n = atoi("3"); //argv[1]
    f2 = fopen("file_2.txt", "r"); //argv[2]
    char c = 0;
    int num = 0;
    fseek(f2, 0, SEEK_SET);
    while ((c = fgetc(f2)) != EOF) {
        if (c == '\n') {
            num++;
        }
    }
    num++;
    struct stat buff;
    stat("file_2.txt", &buff); //argv[2]
    char symb;
    int pos = 0;
    printf("%d\n", buff.st_size);
    int count = 0;
    fseek(f2, -1, SEEK_END);
    FILE* f1;
    f1 = fopen("file.txt", "w");
    while (pos < n) {
        count++;
        fread(&symb, sizeof(symb), 1, f2);
        if (symb == '\n') {
            pos++;
        }
        fseek(f2, -(count), SEEK_END);
        fputc(symb, f1);
    }
    if (pos == num) {
        fseek(f2, 0, SEEK_SET);
        while ((c = fgetc(f2)) != EOF) {
            printf("%c", c);
        }
    }
    fclose(f1);
    f1 = fopen("file.txt", "r");
    struct stat buff2;
    stat("file.txt", &buff2); //argv[2]
    char s[buff2.st_size];
    fseek(f1, 0, SEEK_SET);
    int cnt = 0;
    char sym;
    if ((pos != num) | (num-n == 1)) {
        while ((sym = fgetc(f1)) != EOF) {
            //printf("%s", s);
            s[buff2.st_size-cnt-1] = sym;
            cnt++;
        }
        int h = 0;
        for (h = 1; h < buff2.st_size; h++) {
            printf("%c", s[h]);
        }
    }
    return 0;
}