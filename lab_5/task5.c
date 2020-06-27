#include <stdio.h>
#include <unistd.h>
#include <sys/param.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
    DIR *dir;
    struct dirent *inf;
    struct stat info;
    char dir_name[MAXPATHLEN];
    char f_l[2];
    char c;
    scanf("%s", f_l);
    c = getchar();
    if(c != '\n' ) {
        scanf("%s", dir_name);
    }else {
        getcwd(dir_name, MAXPATHLEN);
    }
    dir = opendir(dir_name);
    while ((inf = readdir(dir)) != NULL) {
        if (f_l[0] == '-') {
            printf("d_ino = %lu\nd_name = %s\nd_type = %d\nd_reclen = %d\n \n", inf->d_ino, inf->d_name, inf->d_type, inf->d_reclen);
            stat(inf->d_name, &info);
            printf("st_dev = %lu\nst_mode = %o\nst_uid = %u\nst_gid = %u\nst_size = %lu\nst_blocks = %ld\nst_ctime = %ld\n", info.st_dev, info.st_mode, info.st_uid, info.st_gid, info.st_size, info.st_blocks, info.st_ctime);
        } else {
            printf("d_name = %s\n", inf->d_name);
        }
    }
    closedir(dir);
    return 0;
}

//struct dirent {
//    ino_t          d_ino;  inode number
//    off_t          d_off;   offset to the next dirent
//    unsigned short d_reclen;   length of this record
//    unsigned char  d_type;   type of file;
//    char           d_name[256]; filename