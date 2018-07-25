/*sigaction函数的用法
 *
 * 当进程首次收到SIGINT（Ctrl+c）时在终端打印Ouch信息
 * 后续又恢复到默认的处理方法*/

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

/*信号处理函数*/
void ouch(int sig)
{
	printf("\nOuch! - I got signal %d\n", sig);
}

int main(int argc, char *argv)
{
	struct sigaction act;

	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask); /*清空屏蔽信号集*/
	act.sa_flags = SA_RESETHAND;

	sigaction(SIGINT, &act, NULL);

	while(1)
	{
		printf("sleeping\n");	
		sleep(1);
	}

	return 0;
}
