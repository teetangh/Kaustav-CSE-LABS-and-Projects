#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct{
	int n;
	int * arr;
}Fibonacci;

void * fib_gen(void * param){
	Fibonacci * fib = (Fibonacci *)param;
	fib->arr[0] = 0, fib->arr[1] = 1;
	for(int i= 2; i<fib->n; i++)
		fib->arr[i] = fib->arr[i-1] + fib->arr[i-2];
}

int main(int argc, char const *argv[])
{
	printf("Enter n : ");
	int n;
	scanf("%d", &n);
	pthread_t thread;
	Fibonacci fib;
	fib.n = n;
	fib.arr = malloc(n * sizeof(int));
	pthread_create(&thread, NULL, &fib_gen, (void *)&fib);
	pthread_join(thread, NULL);
	for(int i=0; i<n; i++)
		printf("%d ", fib.arr[i]);
	return 0;
}
