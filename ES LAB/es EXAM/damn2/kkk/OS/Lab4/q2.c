#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int status;
	pid_t pid;
	pid = fork();
	switch(pid){
		case -1:
			perror("Fork Failed\n");
			exit(1);
		case 0:
			execl("/home/170905142/Labs/OS/Lab4/q1.c", "/home/170905142/Labs/OS/Lab4/q1.c", NULL);
			exit(1);
		default: 
			wait(&status);
			printf("Child Completed\n");
			break;
	}
}