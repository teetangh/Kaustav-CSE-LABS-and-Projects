#include <stdio.h>
#include <stdlib.h>
#include "myIntQueue.h"

int constructGraph(int adjacencyMatrix[100][100], int vertices, int ver1, int ver2)
{
	adjacencyMatrix[ver1][ver2] = 1;
	adjacencyMatrix[ver2][ver1] = 1;
}

int printGraph(int adjacencyMatrix[100][100], int vertices)
{
	for (int i = 0; i < vertices; ++i)
	{
		for (int j = 0; j < vertices; j++)
		{
			printf(" %d ", adjacencyMatrix[i][j]);
		}
		printf(" \n");
	}
}

void myBFSnew(queue *q, int adjacencyMatrix[100][100], int vertices, int start, int visited[])
{
	visited[start] = 1;
	printf(" Visited %d \n", start);

	while (!isEmpty(q))
		dequeue(q);

	enqueue(q, start);

	while (!isEmpty(q))
	{
		for (int k = 0; k < vertices; k++)
		{
			// printf("\n  K value is %d \n",k);
			if (adjacencyMatrix[q->front][k] == 1 && !visited[k])
			{
				visited[k]++;
				printf(" Visited %d \n", k);
				enqueue(q, k);
			}
		}
		// myBFSnew(q,adjacencyMatrix,vertices,dequeue(q),visited);
		// printf("\n Displaying queue \n");
		// display(q);
		// printf("\n Displaying Visited Array\n");
		// for(int i = 0; i<vertices; i++)
		// 	printf(" %d ",visited[i]);
		// printf("\n");
		dequeue(q);
	}
}

int main()
{

	int adjacencyMatrix[100][100];
	int vertices;
	int edges;
	int ver1, ver2;

	printf("Please Enter the number of vertices  and edges \n");
	scanf(" %d%d", &vertices, &edges);

	printf("constructGraph\n");
	for (int i = 0; i < edges; ++i)
	{
		scanf(" %d%d", &ver1, &ver2);
		constructGraph(adjacencyMatrix, vertices, ver1, ver2);
	}

	printGraph(adjacencyMatrix, vertices);

	int *visited = (int *)calloc(vertices, sizeof(int));

	printf(" printing visited array\n");
	for (int i = 0; i < vertices; ++i)
		printf(" %d ", visited[i]);
	printf("\n");

	queue Q;
	int start;
	printf(" Just enter the start vertex \n");
	scanf(" %d", &start);
	myBFSnew(&Q, adjacencyMatrix, vertices, start, visited);

	// for (int j = 0; j < vertices; j++)
	// {
	// 	if (!visited[j])
	// 		myBFSnew(&Q, adjacencyMatrix, vertices, j, visited);
	// }
}