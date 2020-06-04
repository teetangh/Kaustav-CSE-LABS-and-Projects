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
	char some_text[2];
};

int main()
{
	pid_t pid ;
	struct  shared_use_st * shared_stuff ;
	int shmid = shmget((key_t) 1234 , sizeof(struct shared_use_st),0666|IPC_CREAT);
	if(shmid== -1)
	{
		printf("Error\n");
		exit(1);
	}
	void * shared_memory = shmat(shmid , (void *) 0,0);
	if(shared_memory == (void *) -1)
	{
		printf("Error\n");
		exit(1);
	}
	printf("Memory attached at %X\n",(int)shared_memory);
	shared_stuff = (struct shared_use_st *)shared_memory ;
	printf("Enter character to send to child\n");
	scanf("%c",&(shared_stuff->some_text[0]));
	pid = fork();
	if(pid==0)
	{
		printf("Child process starting now\n");
		//int shmid = shmget((key_t) 1234 , sizeof(struct shared_use_st),0666|IPC_CREAT);
		printf("Parent entered %c\n",shared_stuff->some_text[0]);
		char c ;
		if(shared_stuff->some_text[0]==122)
		{
			c = 'a';
		}
		else if(shared_stuff->some_text[0]==90)
		{
			c = 'A';
		}
		else
		{
			c = shared_stuff->some_text[0]+1 ;
		}
		shared_stuff->some_text[1]=c ;


	}
	else
	{
		
		wait(NULL);
		printf("Next character from child is %c\n",shared_stuff->some_text[1]);
	}


}