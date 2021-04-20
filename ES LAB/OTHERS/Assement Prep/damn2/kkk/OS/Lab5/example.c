#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void* thread_code(void * param)
{
	int id=(int*) param;
	printf("I am a child thread, aur yeh he meri keemat Rs.%d \n",param );
	return (void *)param;

}

int main()
{
	int i;
	int return_val[10];

	
	pthread_t thread[10];
	for (i = 0; i < 10; i++)
		pthread_create(&thread[i],0,&thread_code,(void*) i);

	for(i=0;i<10;i++){
		pthread_join( thread[i],(void**)&return_val[i]);
		printf("Child thread %i terminated, evil laughs\n",return_val[i]);

	}

	return 0;
}