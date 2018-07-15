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

	if(wait(&status) != pid)
	{
		perror("fork error");
		exit(-1);
	}
	print_exit_status(status); /*打印退出转台信息*/


	/*创建第二个子进程*/
	if((pid = fork()) < 0)
	{
		perror("fork error");
		exit(-1);
	}
	else if(pid == 0)
	{
		abort(); /*子进程调用abort()函数异常退出*/
	}

	if(wait(&status) != pid) /*父进程等待子进程退出，并获取退出状态*/
	{
		perror("fork error");
		exit(-1);
	}
	print_exit_status(status); /*打印第二个退出状态信息*/
	
	return 0;
}
