#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char * path = "/home/170905142/Labs/OS/Lab7/prg2/file";
	int arr[4];
	int i ;
	while(1)
	{
		int fd = open(path,O_WRONLY);
		printf("Enter 4 numbers for the producer to produce.Type first as -1 to quit\n");
		for(i=0;i<=3;i++)
		{
			scanf("%d",&arr[i]);
		}
		int x = write(fd,arr,sizeof(arr));
		if(x==-1)
		{
			perror("\n");
			exit(1);
		}
		//printf("No of bytes written %d\n",x);
		if(arr[0]==-1)
		{
			printf("Producer ending now\n");
			close(fd);
			exit(0);
		}
		close(fd);
	}
}