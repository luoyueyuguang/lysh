#ifndef LY_LYSH_H
#define LY_LYSH_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <termios.h>

#include "consts.h"

int main(int argc, char *argv[]);

static void sig_int(int signo);

static void enable_line_buffering();
static void disable_line_buffering();
#endif // LY_LYSH_H
