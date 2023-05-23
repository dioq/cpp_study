#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define run_log "/home/me/Repository/cpp_study/embed_c/run.log"
#define BUF_LEN 0x400

static char log_buf[BUF_LEN];

void add_log(char *text)
{
    if (strlen(text) <= 0)
    {
        return;
    }
    int fd;
    fd = open(run_log, O_WRONLY | O_CREAT | O_APPEND, 0644);
    time_t t = time(0);
    char *timestr = asctime(localtime(&t));
    char buf[BUF_LEN];
    bzero(buf, BUF_LEN);
    if (fd == -1)
    {
        sprintf(buf, "%s%s %d %s\n", timestr, __FILE__, __LINE__, strerror(errno));
        add_log(buf);
        close(fd);
        exit(EXIT_FAILURE);
    }

    sprintf(buf, "%s%s", timestr, text);
    write(fd, buf, strlen(buf));
    close(fd);
}

int main(int argc, char *argv[])
{
    // printf("%s %d current pid: %d\n", __FILE__, __LINE__, getpid());
    add_log("A new elf was loaded!");
    // printf("argc = %d\n", argc);
    // for (int i = 0; i < argc; i++)
    // {
    //     printf("argv[%d] = %s\n", i, argv[i]);
    // }
    bzero(log_buf, BUF_LEN);
    sprintf(log_buf, "%s %d A new process was created id: %d\n", __FILE__, __LINE__, getpid());
    add_log(log_buf);

    return 0;
}