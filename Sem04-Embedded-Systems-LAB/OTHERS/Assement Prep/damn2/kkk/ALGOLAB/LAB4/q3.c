//BFS CODE
//Input - adjacency matrix represting graph
//Solved using stack
//If (i,j) = 1, means there is a edge between vertices i and j

#include <stdio.h>
#include <stdlib.h>

int graph[10][10];
int visited[10];
int queue[10];
int n;
int rear = -1;
int front = -1;

void enqueue(int item)
{
	queue[++front] = item;
}

void dequeue()
{
	++rear;
}

void display()
{
	for (int i = 0; i <= front; i++)
		printf("%d ", queue[i]);
	printf("\n");
}

void BFS(int node)
{
	if (visited[node] == 0)
	{
		visited[node] = 1;
		enqueue(node);
	}

	for (int j = 0; j < n; j++)
	{
		if (graph[node][j] == 1 && visited[j] == 0)
		{
			visited[j] = 1;
			enqueue(j);
		}
	}
	if (front != rear)
	{
		dequeue();
		BFS(queue[rear]);
	}
}

int main(void)
{
	printf("How many elements? ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			scanf("%d", &graph[i][j]);
	}
	for (int i = 0; i < n; i++)
		visited[i] = 0; //None of the nodes have been visited yet

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0)
			BFS(i);
	}
	printf("\nBFS traversal: ");
	display();
}