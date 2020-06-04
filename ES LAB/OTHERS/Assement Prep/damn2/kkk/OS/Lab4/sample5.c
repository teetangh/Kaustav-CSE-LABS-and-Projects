#include<stdio.h>
#include <unistd.h>
#include<stdlib.h>
#include <sys/types.h>


int main(int argc, char **argv){

	char *cmdargs[] = {"grep", "-I", "-n", "SUMIT", "/etc/passed", NULL};
	execv("/bin/grep", cmdargs );
	printf ("execv error\n");
}