#ifndef LY_OUTPUT_H
#define LY_OUTPUT_H

#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h>

#define blue "\033[0;34m"
#define green "\033[0;32m"
#define red "\033[0;31m"
#define yellow "\033[0;33m"
#define cyan "\033[0;36m"
#define magenta "\033[0;35m"
#define white "\033[0;37m"
#define black "\033[0;30m"
#define bold "\033[1m"
#define underline "\033[4m"
#define blink "\033[5m"
#define reverse "\033[7m"


#define reset "\033[0m"

enum color {
    BLUE,
    GREEN,
    RED,
    YELLOW,
    CYAN,
    MAGENTA,
    WHITE,
    BLACK,
    BOLD,
    UNDERLINE,
    BLINK,
    REVERSE,
    RESET
};

void output(char *str, enum color c);

#endif // LY_OUTPUT_H
