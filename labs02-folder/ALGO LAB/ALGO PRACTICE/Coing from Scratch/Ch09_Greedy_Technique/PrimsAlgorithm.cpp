// Spanning Tree
// if Graph has G(V,E)
// then Spanning Tree will have G'(V',E')
// where V' = V = n
// and E'= V - 1 = n - 1
// MST = minimum spanning tree adds the concept of weights and it is the ST with minmimum sum of wts
// Grpah should be weighted, connected and directed
#include <iostream>
#include <climits>

using namespace std;
class Edge
{
public:
    int source;
    int dest;
    int weight;
};

int findMinVertex(int *weights, bool *visited, int n)
{
    // Let the initial minVertex be -1
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        // Short circuit Opertator
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
            minVertex = i;
    }
    return minVertex;
}

void Prims(int **edges, int n)
{
    // Creating the required arrays
    int *parent = new int[n];
    int *weights = new int[n];
    bool *visited = new bool[n];

    // Initialising the required arrays
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    // For the Source Vertex
    parent[0] = -1;
    weights[0] = 0;

    // Find the current minimum Vertex
    for (int i = 0; i < n; i++)
    {
        // Find minVertex
        int minVertex = findMinVertex(weights, visited, n);
        visited[minVertex] = true;

        // Explore the unvisited neighbours
        for (int j = 0; j < n; ++j)
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weights[j])
                {
                    weights[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }
    printf("The Prims MST is\n");

    for (int i = 1; i < n - 1; i++)
    {
        if (parent[i] < i)
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        else
            cout << i << " " << parent[i] << " " << weights[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n, e;
    cin >> n >> e;

    // KRUSKAL
    // Edge *input = new Edge[E];
    // for (int i = 0; i < E; i++)
    // {
    //     int s, d, w;
    //     cin >> s >> d >> w;
    //     input[i].source = s;
    //     input[i].dest = d;
    //     input[i].weight = w;
    // }

    // PRIMS
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int f, s, weight;
        cin >> f >> s >> weight;
        edges[f][s] = weight;
        edges[s][f] = weight;
    }

    cout << endl;
    Prims(edges, n);

    return 0;
}
// // Sample IO 1
// 6 11
// 0 1 2
// 1 3 1
// 0 2 4
// 2 4 9
// 4 5 5
// 3 5 7
// 4 3 11
// 2 5 10
// 0 3 3
// 2 1 8
// 2 3 6

// The Prims MST is
// 0 1 2
// 0 2 4
// 1 3 1
// 4 5 5
// 3 5 7

// // Sample IO 2
// 5 7
// 0 1 4
// 0 2 8
// 1 3 6
// 1 2 2
// 2 3 3
// 2 4 9
// 3 4 5

// The Prims MST is
// 0 1 4
// 1 2 2
// 2 3 3
// 3 4 5