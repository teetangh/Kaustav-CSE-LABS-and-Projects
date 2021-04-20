#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int graph[10][10];
int visited[10];
int stack[10];
int n;
int top = -1;
int pop_c = 0;
int poporder[10];

void push(int item)
{
	stack[++top] = item;
}

void pop()
{
	int item = stack[top];
	top--;
	poporder[pop_c++] = item;
}

void display()
{
	for (int i = 0; i <= top; i++)
		printf("%d ", stack[i]);
	printf("\n");
}

void DFS(int node)
{
	if (visited[node] == 0)
	{
		visited[node] = 1;
		push(node);
	}

	int j = 0;
	bool flag = false;
	for (j = 0; j < n; j++)
	{
		if (graph[node][j] == 1 && visited[j] == 0)
		{
			flag = true;
			break;
		}
	}
	if (flag)
	{
		node = j;
		DFS(node);
	}
	else
	{
		pop();
		if (top != -1)
			DFS(stack[top]);
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
			DFS(i);
	}
	printf("\n");

	printf("\n");
	for (int i = n - 1; i >= 0; i--)
		printf("%d ", poporder[i]);
	printf("\n");
}