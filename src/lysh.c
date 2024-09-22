#include "lysh.h"
#include "output.h"
#include "execute.h"
#include "complete.h"

extern int parse_and_execute(char *buf);
extern char* auto_complete(char *input);

int main(int argc, char *argv[]){
    char* buf;
    int buf_len = 0;
    
    if(signal(SIGINT, sig_int) == SIG_ERR){
        printf("signal error\n");
    }

    char c;
    enum color color;
    buf = (char *)malloc(MAXLINE);

    disable_line_buffering();
    while(1){
        output("lysh% ", color = BLUE);
        while((c = getchar()) != '\n'){
            if(c == '\t'){
                buf[buf_len++] = '\0';
                char* tmp = auto_complete(buf);
                printf("\r\033[K");
                if(tmp == NULL){
                    output("lysh% ", color =BLUE);
                    printf("%s", buf);
                }
                else{
                    output("lysh% ", color =BLUE);
                    buf_len = strlen(tmp) + 1;
                }
                continue;
            }
            buf[buf_len++] = c;
        }
        buf[buf_len] = '\0';
        if(signal(SIGINT, sig_int) == SIG_ERR){
            printf("signal error\n");
        }
        parse_and_execute(buf);
        buf_len = 0;
        printf("\n");
    }
    enable_line_buffering();
    exit(0);
}

void sig_int(int signo){
    enum color color;
    output("interrupt\n%% ", color = RED);
    exit(0);
}

void disable_line_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag &= ~ICANON;  // 禁用缓冲
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}

// 启用行缓冲
void enable_line_buffering() {
    struct termios t;
    tcgetattr(STDIN_FILENO, &t);
    t.c_lflag |= ICANON;   // 启用缓冲
    tcsetattr(STDIN_FILENO, TCSANOW, &t);
}
