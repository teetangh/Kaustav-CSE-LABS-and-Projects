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
	printf("Starting consumer process now\n");
	struct shared_use_st * shared_stuff ;
	srand((unsigned int)getpid());
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
	shared_stuff->pwait = 0 ;
	while(1)
	{
		//printf("Hello\n");
		if(shared_stuff -> pwait ==1)
		{
			//printf("Abcd\n");
			printf("Producer produced %s\n",shared_stuff->some_text);
			sleep(rand() % 4);
			shared_stuff->pwait = 0 ;
			if(strcmp(shared_stuff->some_text,"q")==0)
			{
				break ;
			}
		}
	}
	if(shmdt(shared_memory)==-1)
	{
		printf("Error\n");
		exit(1);
	}
	if(shmctl(shmid,IPC_RMID,0)==-1)
	{
		printf("Error\n");
		exit(1);
	}
	 exit(0);

}