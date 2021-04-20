#include <stdio.h>
#include <stdlib.h>

int graph[10][10];
int n;
int visited[10];
int removed[10];
int count = 0;
void removeNode(int);
int noinEdges(int node)
{
	for (int i = 0; i < n; i++)
	{
		if (graph[i][node] == 1)
			return 0;
	}
	return 1;
}
void sourceRemoval()
{
	for (int node = 0; node < n; node++)
	{
		if (visited[node] == 0)
		{
			if (noinEdges(node) == 1)
				removeNode(node);
		}
	}
}
void removeNode(int node)
{
	visited[node] = 1;
	removed[count] = node;
	for (int j = 0; j < n; j++)
	{
		graph[node][j] = 0;
	}
	count++;
	sourceRemoval();
}
int main(void)
{
	printf("Enter number of nodes: ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
	}
	for (int i = 0; i < n; i++)
		visited[i] = 0;

	sourceRemoval();
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", removed[i]);
	printf("\n");
}
