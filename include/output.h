#ifndef LY_OUTPUT_H
#define LY_OUTPUT_H

#include <stdio.h>
#include <sys/stat.h> 
#include <sys/types.h>

#define blue "\033[0;34m"

#define reset "\033[0m"

void output(const char *str);

#endif // LY_OUTPUT_H
