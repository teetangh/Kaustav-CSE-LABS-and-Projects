#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void * thread_Fib( void * size){
	int i,a=0,b=1,c;
	int n=(int*) size;
	int arr[n];
	arr[0]=a;
	arr[1]=b;
	for(i=0;i<n-2;i++)
	{
		c=a+b;
		a=b;
		b=c;
		arr[i+2]=c;
	}

	return (void *)arr;
}

int main(){
	int i,n;

	pthread_t thread;
	printf("Enter number of terms you want for your very own Fibonacci series :\n");
	scanf("%d",&n);
	int *arr;
	void *temp;
	pthread_create(&thread,0,&thread_Fib,(void*)n);
	
	pthread_join(thread, (void**)temp);
	arr=temp;

	printf("Fibonacci series : ");
	for(i=0;i<n;i++)
	{
		printf(" %d ",arr[i]);
	}
	printf("\n");

	return 0;
}