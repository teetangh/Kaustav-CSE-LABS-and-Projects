#include <stdio.h>
#include <pthread.h>

void * sum_gen(void * param){
	int * arr = (int *)param, n = arr[0], sum = 0;
	for(int i=1; i<=n; i++)
		sum += arr[i];
	pthread_exit((void *)sum);
}

int main(int argc, char const *argv[])
{
	printf("Enter n : ");
	int n;
	scanf("%d", &n);
	printf("Enter elements : ");
	int * arr = malloc((n+1) * sizeof(int));
	arr[0] = n;
	for(int i=1; i<=n; i++)
		scanf("%d", &arr[i]);
	pthread_t thread;
	pthread_create(&thread, NULL, &sum_gen, (void *)arr);
	void * sum;
	pthread_join(thread, &sum);
	printf("Sum = %d\n", (int)sum);
	return 0;
}
