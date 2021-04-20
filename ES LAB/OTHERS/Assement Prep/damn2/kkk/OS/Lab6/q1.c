#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*int * jobdo(int arr[])
{
	return arr;
}*/


int main()
{
	int i,j,min,temp,sum=0,burstSum=0,index;
	printf("TAKE INPUT FROM USER NEXT TIME \n");
	//TAKE INPUT FROM USER NEXT TIME
	//TAKE INPUT FROM USER NEXT TIME
	//TAKE INPUT FROM USER NEXT TIME
	//NEXT TIME
	//TAKE INPUT FROM USER NEXT TIME
	int arr[]= {0,1,2,3};
	int arrArrivalt[]= {3,0,4,9};
	int arrBurst[]= {30,60,40,10};
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
			
	waitingTime[0]=0;
	for(i=1;i<n;i++){
		burstSum=0;
		for(j=0;j<i;j++)
			burstSum+=arrBurst[j];
		waitingTime[i]=burstSum-arrArrivalt[i];	
	}

	for(i=0;i<n;i++)
		printf("The waiting time of process %d : %d\n",i,waitingTime[i]);

	for(i=0;i<n;i++)
		sum+=waitingTime[i];

	printf("The average waiting Time is : %d \n",(sum/4));

	for(i=0;i<n;i++){
		turnAroundTime[i]=waitingTime[i]+arrBurst[i];	
	}
	for(i=0;i<n;i++)
		printf("The turnAroundTime time of process %d : %d\n",i,turnAroundTime[i]);
	sum=0;
	for(i=0;i<n;i++)
		sum+=turnAroundTime[i];

	printf("The average turnAroundTime  is : %d \n",(sum/4));

}

	 
