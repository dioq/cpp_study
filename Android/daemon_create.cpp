#include <jni.h>
#include <string>
#include <android/log.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LOG_TAG "navtive_run_log"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)

void run_task()
{
    while (true)
    {
        LOGI("native function is running .....");
        sleep(5);
    }
}

// 创建一个守护进程
void creat_daemon()
{
    LOGI("111111");
    char log_buf[0x1000];
    pid_t pid;
    pid = fork();
    LOGI("2222222");
    if (pid == 0)
    {
        LOGI("33333");
        chdir("/");
        for (int i = 0; i < 3; i++)
        {
            close(i);
        }
        umask(0);
        LOGI("2222");

        sprintf(log_buf, "%s %d daemon pid: %d\n", __FILE__, __LINE__, getpid());
        LOGI("%s", log_buf);
        run_task();
    }
    else if (pid < 0)
    {
        sprintf(log_buf, "%s %d fork fail:%s\n", __FILE__, __LINE__, strerror(errno));
        LOGI("%s", log_buf);
    }
}

extern "C"
    [[noreturn]] JNIEXPORT void JNICALL
    Java_cn_my_forknewprocess_MainActivity_fork_1start(JNIEnv *env, jobject thiz)
{
    creat_daemon();
}
