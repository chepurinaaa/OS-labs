#include <stdio.h>
#include <sys/stat.h>

int main() {
    struct stat info;
    stat("file_2.txt", &info);
    printf("st_dev = %lu\nst_mode = %o\nst_uid = %u\nst_gid = %u\nst_size = %lu\nst_blocks = %ld\nst_ctime = %ld\n", info.st_dev, info.st_mode, info.st_uid, info.st_gid, info.st_size, info.st_blocks, info.st_ctime);
    return 0;
}