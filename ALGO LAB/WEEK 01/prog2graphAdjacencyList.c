#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex;
    struct node *next;
};
struct Graph
{
    int numVertices;
    struct node **adjLists;
};

struct node *createNode(int v)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int vertices)
{
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node *));

    int i;
    for (i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{
    // Add edge from src to dest
    struct node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void printGraph(struct Graph *graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node *temp = graph->adjLists[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertices;
    int ch, ver1, ver2;
    printf("Enter number of vertex\n");
    scanf("%d", &vertices);
    struct Graph *graph = createGraph(vertices);
    while (1)
    {
        printf("Enter\n1.Add Edge\n2.Print Graph\n3.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter two vertices\n");
            scanf("%d%d", &ver1, &ver2);
            addEdge(graph, ver1, ver2);
            break;

        case 2:
            printGraph(graph);
            break;

        case 3:
            exit(0);
        }
    }
    return 0;
}
