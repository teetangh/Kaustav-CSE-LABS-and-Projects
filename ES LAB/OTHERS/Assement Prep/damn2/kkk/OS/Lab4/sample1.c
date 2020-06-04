#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>

int main(){
	char dirname[10];
	DIR *p;
	struct dirent *d;
	printf("Enter directory name:\n");
	scanf("%s",dirname);
	//printf("11111111\n");
	p=opendir(dirname);
	//printf("222222222\n");
	if(p==NULL){
		printf("cant find directory");
		exit(-1);
	}
	while(d = readdir(p));
		printf("222222222\n");
		printf("%s\n",d->d_name);
		return 0;
}