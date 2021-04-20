#include <stdio.h>
int main(){
int arr[]={3,1,2,4};
int i=0;
int a=0;
int j=0;
for(i;i<3;i++)
	for(j;j<3;j++){
		if (arr[j]>arr[j+1]){
			a=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=a;
		}
	}
for(i=0;i<4;i++)
	printf("%d \n",arr[i]);
return 0;
}

