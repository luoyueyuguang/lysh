#ifndef LY_LYSH_H
#define LY_LYSH_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#include "consts.h"

int main(int argc, char *argv[]);

static void sig_int(int signo);

#endif // LY_LYSH_H
