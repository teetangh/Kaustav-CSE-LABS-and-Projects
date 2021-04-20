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
#include<sys/shm.h>

struct shared_use_st
{
	int pwait ;
	char some_text[2048];
};

int main()
{
	printf("Starting producer process now\n");
	struct shared_use_st * shared_stuff ;
	char buffer[2048];
	int shmid = shmget((key_t)1234 , sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid==-1)
	{
		printf("Error\n");
		exit(1);
	}
	void * shared_memory = shmat(shmid,(void *)0,0);
	if(shared_memory == (void*)-1)
	{
		printf("Error\n");
		exit(1);
	}
	printf("Memory attached at %X\n",(int)shared_memory);
	
	shared_stuff = (struct shared_use_st *) shared_memory ; 
	shared_stuff -> pwait =  0;
	while(1)
	{
		while(shared_stuff -> pwait ==1)
		{
			sleep(5);
			printf("Waiting for consumer to consume\n");
		}
		printf("Enter some text or q to exit\n");
		gets(buffer);
		strcpy(shared_stuff->some_text,buffer);
		shared_stuff -> pwait = 1 ;
		if(strcmp(buffer,"q")==0)
		{
			break ;
		}
	}
	if(shmdt(shared_memory)==-1)
	{
		printf("Error\n");
		exit(1);
	}
	exit(0);
}