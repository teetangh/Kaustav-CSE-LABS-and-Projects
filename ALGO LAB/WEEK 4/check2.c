#include <stdio.h>
#include <stdlib.h>

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

void myDFSnew(int adjacencyMatrix[100][100], int vertices, int start, int visited[])
{
	visited[start] = 1;
	printf(" visited %d \n", start);

	for (int k = 0; k < vertices; k++)
	{
		if (adjacencyMatrix[start][k] == 1 && visited[k] == 0)
			myDFSnew(adjacencyMatrix, vertices, k, visited);
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

	// int start;
	// printf(" Just enter the start vertex \n");
	// scanf(" %d", &start);
	// myDFSnew(adjacencyMatrix, vertices, start, visited);

	for(int j = 0 ; j < vertices ; j++)
	{
		if(!visited[j])
			myDFSnew(adjacencyMatrix,vertices,j,visited);

	}
}