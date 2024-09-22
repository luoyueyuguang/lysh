#include "output.h"

void output(char *str, enum color color) {
    switch (color) {
        case BLACK:
            printf(black);
            break;
        case RED:
            printf(red);
            break;
        case GREEN:
            printf(green);
            break;
        case YELLOW:
            printf(yellow);
            break;
        case BLUE:
            printf(blue);
            break;
        case MAGENTA:
            printf(magenta);
            break;
        case CYAN:
            printf(cyan);
            break;
        case WHITE:
            printf(white);
            break;
        default:
            printf(reset);
            break;
    }
    printf("%s", str);
    printf(reset);
}

