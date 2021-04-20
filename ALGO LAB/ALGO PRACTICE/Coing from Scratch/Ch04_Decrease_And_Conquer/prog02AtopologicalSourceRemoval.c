/*
 * Created on Tue Jun 02 2020
 *
 * Copyright (c) 2020 Kaustav Ghosh
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "include/KaustavGraph.h"

void topologicalSourceRemoval(KaustavGraph *myGraph)
{
    // Valid only for DAG (Directed Acylic Graphs)
    int vertexIndegree0 = 0;
    int *visitedArray = (int *)calloc(myGraph->vertices, sizeof(int));

    for (int col = 0; col < myGraph->vertices; col = (col + 1) % myGraph->vertices)
    {
        if (!visitedArray[col])
        {
            // printf("\n selected vertex %d for scanning \n", col);
            bool flagEmptyColumn = true;
            for (int row = 0; row < myGraph->vertices; row++)
            {
                if (myGraph->adjacencyMatrix[row][col] == 1)
                {
                    // printf("\n Broken vertex %d while scanning \n", row);
                    flagEmptyColumn = false;
                    break;
                }
            }
            if (flagEmptyColumn == true)
            {
                vertexIndegree0 = col;
                visitedArray[vertexIndegree0] = 1;
                printf("Visited vertex %d\n", vertexIndegree0);
            }
            for (int col2 = 0; col2 < myGraph->vertices; col2++)
                myGraph->adjacencyMatrix[vertexIndegree0][col2] = 0;
        }

        bool completed = true;
        for (int i = 0; i < myGraph->vertices; i++)
        {
            if (!visitedArray[i])
            {
                completed = false;
                break;
            }
        }
        if (completed)
            return;
    }
}

int main()
{
    KaustavGraph myGraph;
    initialiseGraph(&myGraph);

    printf("Enter the number of vertices and edges \n");
    int v, e;
    scanf(" %d %d", &v, &e);
    myGraph.vertices = v;
    myGraph.edges = e;

    printf("Enter the edges \n");
    for (int i = 0; i < e; i++)
    {
        int f, s;
        scanf(" %d %d", &f, &s);
        addDirectedEdge(&myGraph, f, s);
    }

    printAdjacencyMatrix(&myGraph);
    printf("\n Topological Sort is: \n");
    topologicalSourceRemoval(&myGraph);
}

// // Sample IO
// Enter the number of vertices and edges
// 6
// 6
// Enter the edges
// 5 2
// 5 0
// 4 0
// 4 1
// 2 3
// 3 1
//     0 1 2 3 4 5 6 7 8 9
//     -------------------
// 0 : 0 0 0 0 0 0 0 0 0 0
// 1 : 0 0 0 0 0 0 0 0 0 0
// 2 : 0 0 0 1 0 0 0 0 0 0
// 3 : 0 1 0 0 0 0 0 0 0 0
// 4 : 1 1 0 0 0 0 0 0 0 0
// 5 : 1 0 1 0 0 0 0 0 0 0
// 6 : 0 0 0 0 0 0 0 0 0 0
// 7 : 0 0 0 0 0 0 0 0 0 0
// 8 : 0 0 0 0 0 0 0 0 0 0
// 9 : 0 0 0 0 0 0 0 0 0 0

//  Topological Sort is:
// Visited vertex 4
// Visited vertex 5
// Visited vertex 0
// Visited vertex 2
// Visited vertex 3
// Visited vertex 1

// DIRECT GRAPH
//     5   4
//    / \ / \
//   2   0   1
//     \   /
//       3