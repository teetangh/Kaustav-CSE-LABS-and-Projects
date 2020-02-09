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

void topologicalDFSHelper(int adjacencyMatrix[100][100], int vertices, int *visitedArray, stack *visitedSet, stack *sortedSet)
{
    int stackTop = visitedSet->top;

    for (int col = 0; col < vertices; col++)
    {
        if (adjacencyMatrix[stackTop][col] == 1 && !visitedArray[col])
        {
            push(&visitedSet, stackTop);
            topologicalDFSHelper(adjacencyMatrix, vertices, visitedArray, visitedSet, sortedSet);
        }
    }
}
void topologicalDFS(int adjacencyMatrix[100][100], int vertices, int *visitedArray, stack *visitedSet, stack *sortedSet)
{
    int vertexIndegree0 = 0;

    for (int col = 0; (col % vertices) < vertices; col = ((col + 1) % vertices))
    {
        if (adjacencyMatrix[0][col] == 0 && !visitedArray[col])
        {
            bool flagEmptyColumn = true;
            for (int row = 0; row < vertices; row++)
            {
                if (adjacencyMatrix[row][col] == 1)
                {
                    flagEmptyColumn = false;
                    break;
                }
            }
            if (flagEmptyColumn == true)
            {
                vertexIndegree0 = col;
                visitedArray[vertexIndegree0] = 1;
                printf("Visited vertex %d\n", vertexIndegree0);

                push(&visitedSet, vertexIndegree0);
                break;
            }
        }
    }

    topologicalDFSHelper(adjacencyMatrix, vertices, visitedArray, visitedSet, sortedSet);
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

    stack visitedSet, sortedSet;
}
