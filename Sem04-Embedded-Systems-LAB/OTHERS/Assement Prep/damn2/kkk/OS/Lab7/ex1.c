#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int n;
	int fd[2];
	char buf[1025];
	char *data= "hello this is sample data";
	pipe(fd);
	write(fd[1],data,strlen(data));
	n=read(fd[0],buf,1024);
	if(n>=0){
		buf[n]='\0';
		printf("Read %d bytes from the pipe : %s \n",strlen(data),buf);
		puts(buf);
		printf("%d\n",n);
	}
	else
		perror("read");



	return 0;
}