#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/msg.h>

#define MAX_TEXT 512

struct msg_st
{
	long int msg_type;
	char text[MAX_TEXT];
};

int main()
{
    int running = 1;
	int msgid = -1;
    struct msg_st data;
    char buffer[BUFSIZ];

	//creat MsgQue
	msgid = msgget((key_t)1234, 0666 | IPC_CREAT);
	if (msgid == -1)
	{
		fprintf(stderr, "msgget failed with error: %d\n", errno);
		exit(EXIT_FAILURE);
	}

    //write msg until writed "end"
    while(running)
    {
        //input data
        printf("Enter some text:");
        fgets(buffer, BUFSIZ, stdin);
        data.msg_type = 1;
        strcpy(data.text, buffer);

        //send msg to msgQue
        if(msgsnd(msgid, (void*)&data, MAX_TEXT, 0) == -1)
        {
            fprintf(stderr, "msgsend failed\n");
		    exit(EXIT_FAILURE);
        }

        //input "end" over
        if(strncmp(buffer, "end", 3) ==0)
            running = 0;
        sleep(1);
    }
    exit(EXIT_FAILURE);
}
