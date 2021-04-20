/*
 * Created on Tue Jun 02 2020
 *
 * Copyright (c) 2020 Kaustav Ghosh
 */

#include <stdio.h>

typedef struct KaustavGraph
{
    int vertices;
    int edges;
    int adjacencyMatrix[10][10];
} KaustavGraph;

void initialiseGraph(KaustavGraph *myGraph)
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            myGraph->adjacencyMatrix[i][j] = 0;
}

void addDirectedEdge(KaustavGraph *myGraph, int firstVertex, int secondVertex)
{
    myGraph->adjacencyMatrix[firstVertex][secondVertex] = 1;
}
void addUndirectedEdge(KaustavGraph *myGraph, int firstVertex, int secondVertex)
{
    myGraph->adjacencyMatrix[firstVertex][secondVertex] = 1;
    myGraph->adjacencyMatrix[secondVertex][firstVertex] = 1;
}
void addWeightedDirectedEdge(KaustavGraph *myGraph, int firstVertex, int secondVertex, int edgeWeight)
{
    myGraph->adjacencyMatrix[firstVertex][secondVertex] = edgeWeight;
}
void addWeightedUndirectedEdge(KaustavGraph *myGraph, int firstVertex, int secondVertex, int edgeWeight)
{
    myGraph->adjacencyMatrix[firstVertex][secondVertex] = edgeWeight;
    myGraph->adjacencyMatrix[secondVertex][firstVertex] = edgeWeight;
}

void printAdjacencyMatrix(KaustavGraph *myGraph)
{

    printf("    ");
    for (int j = 0; j < 10; j++)
        printf("%d ", j);
    printf("\n    -------------------\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%d : ", i);
        for (int j = 0; j < 10; j++)
            printf("%d ", myGraph->adjacencyMatrix[i][j]);
        printf("\n");
    }
}
