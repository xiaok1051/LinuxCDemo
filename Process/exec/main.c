/*exec函数*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*为子进程定义环境变量*/
char *env_init[] = {"USER=peng", "HOME=/home/peng", NULL};

int main(int argc, char *argv[])
{
	pid_t pid;

	if((pid = fork())<0) /*创建进程失败*/
	{
		perror("fork error");	
	}
	else if(pid == 0) /*fork对子进程返回0*/
	{
		/*子进程装载新进程*/
		/*程序名 参数1 参数2 参数3 o 环境变量*/
		execle("sample3", "sample3", "hello", "world", (char *)0, env_init);	
		perror("execle error");
		exit(-1);	
	}
	else
	{
		exit(0);	
	}

	return -1;
}
