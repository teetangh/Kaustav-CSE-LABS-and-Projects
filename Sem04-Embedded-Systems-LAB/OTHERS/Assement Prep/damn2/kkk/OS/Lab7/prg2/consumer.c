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
	while(1)
	{
		int fd = open(path,O_RDONLY);
		int x = read(fd,arr,sizeof(arr));
		if(x==-1)
		{
			perror("\n");
			exit(1);
		}
		if(arr[0]==-1)
		{
			printf("Consumer ending now\n");
			exit(0);
		}
		printf("Integers consumed by consumer\n");
		for(int i=0;i<=3;i++)
		{
			printf("%d ",arr[i]);
		}
		printf("\n");

	}
}