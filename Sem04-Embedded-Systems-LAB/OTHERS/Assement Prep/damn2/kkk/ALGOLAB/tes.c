#include <stdio.h>
#include <stdlib.h>

int visited[10][10];
int arr[10][10];
int cost=0;
int n;

void allPossiblePaths(int city){
	printf("%d--->",city);
	for(int i=0;i<n; i++){
		if(arr[city][i]!=0 && visited[city][i]==0){
			visited[city][i]=1;
			allPossiblePaths(i);
		}
	}
}
int main()
{
	printf("Number of cities: ");
	scanf("%d",&n);
 
	printf("\nCost Matrix\n");
 
	for(int i=0;i < n;i++){
		for(int j=0;j < n;j++){
			scanf("%d",&arr[i][j]);
			visited[i][j]=0;
		}
	}
 
	printf("\n\nThe Path is:\n");
	allPossiblePaths(0);
	printf("\n\nMinimum cost is %d\n ",cost);
 
	return 0;
}