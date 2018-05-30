#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

/*出错处理宏供返回错误码的函数使用*/
#define handle_error_en(en, msg)    do{errno = en; perror(msg); exit(EXIT_FAILURE);}while(0)

/*出错处理宏*/
#define handel_error(msg)   do{perror(msg); exit(EXIT_FAILURE);}while(0)

struct thread_info {
    pthread_t   thread_id;
    int         thread_num;
    char        *argv_string;
};

/*线程函数*/
static void *thread_start(void *arg)
{
    struct thread_info *tinfo = arg;
    char *uargv, *p;

    printf("Thread %d: top of stack neat %p; argv_string = %s\n", tinfo->thread_num, &p, tinfo->argv_string);
    uargv = strdup(tinfo->argv_string);
    if(uargv == NULL;
        handle_error("strdup");

    /*将小写字符转换为大写字符*/
    for (p = uargv; *p != '\0'; p++)
        *p = toupper(*p);

    /*返回转换结果*/
    return uargv;
}

int main(int argc, char *argv[])
{

}
