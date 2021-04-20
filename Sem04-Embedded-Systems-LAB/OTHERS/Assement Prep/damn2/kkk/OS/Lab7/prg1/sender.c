#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<wait.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg_structure
{
	long int msg_type ;
	char text[50];
};

int main()
{
	struct msg_structure msg ;
	int msgid ;
	char buffer[50];
	msgid = msgget((key_t)1234,0666|IPC_CREAT);
	if(msgid==-1)
	{
		printf("There is an error in message queue creation\n");
		exit(1);
	}
	while(1)
	{
		printf("Enter some number or q to exit\n");
		gets(buffer);
		
		msg.msg_type = 1 ;
		strcpy(msg.text,buffer);
		if((msgsnd(msgid,(void*)&msg,50,0))==-1)
		{
			printf("There is an error in sending message to queue\n");
			exit(1);
		}
		if(strcmp(buffer,"q")==0)
		{
			exit(0);
		}
	}
}