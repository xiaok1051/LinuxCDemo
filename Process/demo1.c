/*通过env参数获取环境变量*/

#include <stdio.h>

int main(int argc, char *argv[], char *env[])
{
	int i = 0;
	while(env[i])
	{
		printf("%s\n", env[i++]);
		//puts(env[i++]);
	}

	return 0;
}
