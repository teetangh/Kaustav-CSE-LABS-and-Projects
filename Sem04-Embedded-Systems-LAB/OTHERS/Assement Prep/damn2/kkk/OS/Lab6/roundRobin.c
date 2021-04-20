#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i,j,min,temp,sum=0,burstSum=0,index,rem=5,counter=0;
	printf("TAKE INPUT FROM USER NEXT TIME \n");
	//TAKE INPUT FROM USER NEXT TIME
	//TAKE INPUT FROM USER NEXT TIME
	//TAKE INPUT FROM USER NEXT TIME
	//TAKE INPUT FROM USER NEXT TIME
	int arr[]= {0,1,2,3};
	int arrArrivalt[]= {0,3,4,9};
	int arrBurst[]= {60,30,40,10};
	int arr2Arrivalt[]= {0,3,4,9};
	int arr2Burst[]= {60,30,40,10};
	int runningTime[4];
	int waitingTime[4];
	int turnAroundTime[4];
	int n=4;
	min= arrArrivalt[0];
	index=0;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(arrArrivalt[i]<arrArrivalt[index])
			{
				temp=arrArrivalt[index];
				arrArrivalt[index]=arrArrivalt[i];
				arrArrivalt[i]=temp;

				temp=arrBurst[index];
				arrBurst[index]=arrBurst[i];
				arrBurst[i]=temp;
			}
	for(i=0;i<n;i++)
		waitingTime[i]=0;	
	for(i=0;i<n;i++)
		runningTime[i]=0;

	do{
		i=0;sum=0;
		for (i = 0; i < n; i++)
		{
			if(arrBurst[i]!=0){
				arrBurst[i]=arrBurst[i]-10;
				runningTime[i]+=10;
				waitingTime[i]=counter-runningTime[i];
				counter+=10;
				printf("p%d:%d->",i+1,counter);
			}
			else
				continue;
		}
		for (i = 0; i < n; i++)
			sum+=arrBurst[i];
	}while(sum);  	
	printf("\n");	
	for(i=0;i<n;i++){
		printf("runningTime of p%d = %d\n",i+1,runningTime[i]);
	}
	for(i=0;i<n;i++){
		printf("waitingTime of p%d = %d\n",i+1,waitingTime[i]);
	}
}