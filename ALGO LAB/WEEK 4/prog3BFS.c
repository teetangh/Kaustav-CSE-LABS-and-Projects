#include <stdio.h>
#include <stdlib.h>
#define max_size 5
// QUEUE DATA STRUCTURE
typedef struct
{
    int q[max_size];
    int rear;
    int front;
} Queue;

int isEmpty(Queue q1)
{
    if (q1.front == -1 || q1.front > q1.rear)
        return 1;
    else
        return 0;
}
int isFull(Queue q1)
{
    if (q1.rear == max_size - 1)
        return 1;
    else
        return 0;
}
void addq(Queue *q1, int ele)
{
    if (!isFull(*q1))
    {
        q1->rear++;
        if (q1->front == -1)
        {
            q1->front = 0;
            q1->q[q1->rear] = ele;
        }

        else
            q1->q[q1->rear] = ele;
    }
}
int deleteq(Queue *q1)
{
    if (q1->front == -1 || q1->front > q1->rear)
        return 0;
    else
        return (q1->q[q1->front++]);
}


// GRAPH ADJACNCY MATRIX CREATION
int graph(int a[100][100], int v, int ver1, int ver2)
{
    a[ver1][ver2] = 1;
    a[ver2][ver1] = 1;
}
// BFS
void myBFS(int a[100][100],int vertices ,int start,int visited[])
{
    Queue Q;

    addq(&Q,start);

    while(!isEmpty(Q))
    {
        int p = Q.front;
        int q = deleteq(&Q);
        visited[p]  = 1;
        printf("visited %d \n",p);

        for (int k = 0; (k < vertices) ; k++)
        {
            if(a[p][k] == 1)
            {
                visited[k]  = 1;
                printf("visited %d \n",k);
                addq(&Q,k);
            }
        }
    }
}
int main()
{

    // Creating an EMPTY GRAPH
    int a[100][100];
    int v;
    int ver1;
    int ver2;
    int ex = 0;
    printf("Enter the number of vertices of the graph\n");
    scanf("%d", &v);

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            a[i][j] = 0;
        }
    }
    // Creating the edges
    while (ex != 1)
    {
        printf("Enter the vertices that have an edge\n");
        scanf("%d%d", &ver1, &ver2);
        graph(a, v, ver1, ver2);
        printf("1: to exit.\n0.to continue\n");
        scanf("%d", &ex);
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            printf("%d      ", a[i][j]);
        }
        printf("\n");
    }



    // Doing the ACTUAL BFS
    int* visited = (int *)calloc(v,sizeof(int));
    
    int start;
    printf("Enter the Start vertex for Breadth First Search\n");
    scanf(" %d",&start);

    myBFS(a,v ,start,visited);

    return 0;
}
