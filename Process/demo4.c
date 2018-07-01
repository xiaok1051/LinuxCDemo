/*获取子进程退出状态*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*自定义打印子进程退出状态函数*/
void print_exit_status(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if(WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d\n", WTERMSIG(status));
	else
		printf("other status\n");
}

int main(int argc, char *argv[])
{
	pid_t pid;
	int status;

	/*创建子进程*/
	if((pid = fork()) < 0)
	{
		perror("fork error");	
		exit(-1);
	}
	else if (pid == 0)
	{
		exit(7); /*子进程调用exit函数，参数为7*/
	}




}
