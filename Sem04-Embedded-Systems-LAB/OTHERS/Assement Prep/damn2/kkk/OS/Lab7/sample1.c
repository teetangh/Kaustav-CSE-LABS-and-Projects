#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv){

	int n;
	int fd[2];
	char buf[1025];
	char *data = "this is sample data";
	pipe(fd);
	write(fd[1],data,strlen(data));

	if((n = read(fd[0],buf,1024)) >= 0){
		buf[n] = '\0';
		printf("read %d bytes from the pipe:  %s \n",n,buf);
	}
	else
		perror("read");
	exit(0);	


}