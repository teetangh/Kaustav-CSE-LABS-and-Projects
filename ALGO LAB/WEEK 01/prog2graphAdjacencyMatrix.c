#include <stdio.h>
#include <stdlib.h>

int graph(int a[100][100], int v, int ver1, int ver2)
{
    a[ver1][ver2] = 1;
    a[ver2][ver1] = 1;
}
int main()
{

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

    return 0;
}
