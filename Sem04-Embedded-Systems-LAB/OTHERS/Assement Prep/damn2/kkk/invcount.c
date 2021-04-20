#include <stdio.h>
#include <stdlib.h>

// int invcount = 0;

// void getInvCount(int arr[], int l, int r)
// {
// 	int middle = (r-l)/2;

// 	if(middle >= l)
// 	getInvCount(arr, l, middle);
// 	getInvCount(arr, middle+1, r);

// 	for(int i=l; i<r-1; i++)
// 	{
// 		if(arr[l] <= arr[i+1])
// 			invcount++;
// 	}
// }

void getInvCount(int arr[], int n)
{
	int count = 0;

	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if(arr[i] >= arr[j])
				count++;
		}
	}

	printf("Inversion count is : %d\n", count);
}

int main()
{
	int n;
	printf("Enter array size: \n");
	scanf("%d", &n);

	int arr[n];

	printf("Enter array elements: \n");

	for(int i=0; i<n; i++)
	{
		scanf("%d", &arr[i]);
	}

	// for(int i=0; i<n; i++)
	// {
	// 	printf("%4d", arr[i]);
	// }
	// printf("\n");

	getInvCount(arr, n);

	// printf("Inversion Count is : %d\n", invcount);
}