#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "IntStack.h"

void constructDirectedAcyclicGraph(int **adjacencyMatrix, int ver1, int ver2)
{
    adjacencyMatrix[ver1][ver2] = 1;
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

void topologicalSourceRemoval(int **adjacencyMatrix, int vertices, int *visitedArray)
{
    // bool completed = true;
    // for (int i = 0; i < vertices; i++)
    // {
    //     if (!visitedArray[i])
    //     {
    //         completed = false;
    //         break;
    //     }
    // }
    // if (completed)
    //     return;

    int vertexIndegree0 = 0;

    for (int col = 0; col < vertices; col++)
    {
        if (adjacencyMatrix[0][col] == 0 && !visitedArray[col])
        {
            bool flag = true;
            for (int row = 0; row < vertices; row++)
            {
                if (adjacencyMatrix[row][col] == 1)
                    flag = false;
                break;
            }
            if (flag == true)
            {
                vertexIndegree0 = col;
                visitedArray[vertexIndegree0] = 1;
                printf("Visited vertex %d", vertexIndegree0);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    int adjacencyMatrix[100][100];
    printf("Please enter the numebr of vertices and edges \n");
    scanf(" %d%d", &vertices, &edges);

    int ver1, ver2;
    printf("Please enter the edges in directed Order \n");
    for (int i = 0; i < edges; i++)
    {
        scanf(" %d%d", &ver1, &ver2);
        constructDirectedAcyclicGraph(adjacencyMatrix, ver1, ver2);
    }

    printGraph(adjacencyMatrix, vertices);

    int *visited = (int *)calloc(vertices, sizeof(int));
}
