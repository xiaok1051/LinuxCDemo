/*使用daemon创建守护进程*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>

int main(void)
{
	int fd;
	time_t curtime;

	/*调用daemon函数，创建守护进程*/
	if(daemon(0, 0) == -1)
	{
		perror("deamon error");
		exit(-1);
	}

	fd = open("/tmp/deamon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if(fd < 0)
	{
		perror("open error");	
		exit(-1);
	}

	while(1)
	{
		curtime = time(0);
		char *timestr = asctime(localtime(&curtime));
		write(fd, timestr, strlen(timestr));
		sleep(60);
	}
	close(fd);

	return 0;
}
