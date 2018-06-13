#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid[3];
int sum = 0;
pthread_mutex_t sumlock = PTHREAD_MUTEX_INITIALIZER; /*静态初始化互斥量*/
pthread_cond_t cond_sum_ready = PTHREAD_COND_INITIALIZER; /*静态初始化条件变量*/

void *t1t2(void *arg)
{
	int i;
	long id = (long)arg;

	for(i = 0; i < 60; i++)
	{
		/*使用互斥量保护临界变量*/
		pthread_mutex_lock(&sumlock);
		sum++;
		printf("t%ld: read sum value = %d\n", id+1, sum);
		pthread_mutex_unlock(&sumlock);
		if(sum >= 100)
			pthread_cond_signal(&cond_sum_ready); /*发送条件通知，唤醒等待线程*/
	}

	return NULL;
}

void *t3(void *arg)
{
	pthread_mutex_lock(&sumlock);
	while (sum < 100)
		pthread_cond_wait(&cond_sum_ready, &sumlock);
	sum = 0;
	printf("t3: clear sum value\n");
	pthread_mutex_unlock(&sumlock);

	return NULL;
}

int main(void)
{
	int err;
	long i;


	for (i=0; i<2; i++)
	{
		/*创建线程1线程2*/
		err = pthread_create(&(tid[i]), NULL, &t1t2, (void *)i);
		if (err != 0)
		{
			printf("Can't create thread:[%s]", strerror(err));
		}
	}

	err = pthread_create(&(tid[2]), NULL, &t3, NULL);
	if (err != 0)
	{
		printf("Can't create thread:[%s]", strerror(err));
	}

	for (i=0; i<3; i++)
	{
		pthread_join(tid[i], NULL);
	}

	return 0;
}


