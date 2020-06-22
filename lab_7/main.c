#include <stdio.h>
#include <string.h>

void change_reg(char* ptr_str, int length) {
    while (length != 0) {
        if (length % 4 == 0) {
            (*(int*) ptr_str) ^= 0b100000001000000010000000100000;
            length -= 4;
            ptr_str += 4;
        } else if (length % 8 == 0) {
            (*(long long*) ptr_str) ^= 0b0010000000100000001000000010000000100000001000000010000000100000;
            length -= 8;
            ptr_str += 8;
        } else if (length % 2 == 0) {
            (*(short*) ptr_str) ^= 0b10000000100000;
            length -= 2;
            ptr_str += 2;
        } else {
            (*(char*) ptr_str) ^= 0b100000;
            length -= 1;
            ptr_str += 1;
        }
    }
}

int main() {
    char str[] = "A";
    char* ptr_str = str;
    int length = strlen(str);
    change_reg(ptr_str, length);
    printf("%s", str);
    return 0;
}
