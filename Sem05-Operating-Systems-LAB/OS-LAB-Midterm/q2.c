#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void display_info()
{
	pid_t process_id = getpid();
	pid_t parent_process_id = getppid();

	printf("\n The process_id of the process is %d\n", process_id);
	printf("\n The parent_process_id of the process is %d\n", parent_process_id);
}

int main(int argc, char const *argv[])
{
	pid_t pid;

	pid = fork();

	if (pid == -1)
	{
		fprintf(stderr, "Fork Failed \n");
		exit(0);
	}
	else if (pid == 0)
	{
		display_info();
		printf("\n *********** child process  ***********\n");
		sleep(5);

		printf("\n *********** child process  ***********\n");
		display_info();
	}
	else
	{
		// wait(NULL);
		sleep(1);
		display_info();
		printf("\n *********** parent process *********** \n");
		printf("\nWaiting for the child process \n");

		printf("\n Parent Exiting\n");
		exit(0);
	}
	return 0;
}