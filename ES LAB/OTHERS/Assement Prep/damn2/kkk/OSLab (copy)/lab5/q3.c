#include <pthread.h>
#include <stdio.h>

int is_prime(int x){
	if(x < 2) return 0;
	for(int i=2; i*i<=x; i++)
		if(x%i == 0)
			return 0;
	return 1;
}

void * generate_prime(void * range){
	int * range_int = (int *)range;
	for(int i=range_int[0]; i<=range_int[1]; i++)
		if(is_prime(i)) printf("%d ", i);
	printf("\n");
}

int main(int argc, char const *argv[])
{
	pthread_t thread;
	int range[2];
	printf("Enter range for generating prime nos : ");
	scanf("%d%d", &range[0], &range[1]);
	pthread_create(&thread,NULL,&generate_prime,(void *)range);
	pthread_join(thread, NULL);
	return 0;
}
