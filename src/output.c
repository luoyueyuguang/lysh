#include "output.h"

void output(const char *str) {
    struct stat buf;
    if(stat(str, &buf) == -1) {
        printf("File not found\n");
        return;
    }
    switch (buf.st_mode & S_IFMT) {
        case S_IFREG:
            puts("Regular file");
            break;
        case S_IFDIR:
        {
            printf(blue);
            printf("Directory");
            printf(reset);
            printf("\n");
            break;
        }
        case S_IFCHR:
            puts("Character device");
            break;
        case S_IFBLK:
            puts("Block device");
            break;
        case S_IFIFO:
            puts("FIFO/pipe");
            break;
        case S_IFLNK:
            puts("Symlink");
            break;
        case S_IFSOCK:
            puts("Socket");
            break;
        default:
            puts("Unknown?");
            break;
    }

}

