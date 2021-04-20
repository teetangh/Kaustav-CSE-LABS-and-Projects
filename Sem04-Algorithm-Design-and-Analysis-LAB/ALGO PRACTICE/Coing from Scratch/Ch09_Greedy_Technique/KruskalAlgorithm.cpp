// Spanning Tree
// if Graph has G(V,E)
// then Spanning Tree will have G'(V',E')
// where V' = V = n
// and E'= V - 1 = n - 1
// MST = minimum spanning tree adds the concept of weights and it is the ST with minmimum sum of wts
// Grpah should be weighted, connected and directed
#include <iostream>
#include <algorithm>
using namespace std;
class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int findParent(int v, int *parent)
{
    // If the vertex is the parent of itself
    if (parent[v] == v)
        return v;
    // Otherwise find the parent of this vertex recursively using the parent array
    else
        return findParent(parent[v], parent);
}

void kruskals(Edge *input, int n, int E)
{
    // Sort the input array - ascending order based on weights
    sort(input, input + E, compare);

    // This is for our ouput array
    Edge *output = new Edge[n - 1];

    //Parent Array for the Union Find Algorithm
    int *parent = new int[n];

    // Initialise the parent Array with vertices as their own parents
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int count = 0;
    int i = 0;

    while (count != n - 1)
    {
        Edge currentEdge = input[i];

        // Check if we can add the currentEdge in MST or not
        // Checking in Union Find Algorithm in the sourceParent and DestParent are the same TOPMOST PARENT(Recursively)
        int sourceParent = findParent(currentEdge.source, parent);
        int destParent = findParent(currentEdge.dest, parent);

        if (sourceParent != destParent)
        {
            // True if safe to add to MST based on Union Find
            // In simple words , no cycle detected
            output[count] = currentEdge;
            count++;

            // Updating the parent array based after inserting the edge into the MST
            parent[sourceParent] = destParent;
        }
        i++;
    }

    cout << "The Kruskal MST is" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        // Order must be as per the question
        if (output[i].source < output[i].dest)
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        else
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
    }
}
int main(int argc, char const *argv[])
{
    int n, E;
    cin >> n >> E;

    Edge *input = new Edge[E];

    for (int i = 0; i < E; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    cout << endl;
    kruskals(input, n, E);

    return 0;
}
// // Sample IO
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

// The Kruskal MST is
// 1 3 1
// 0 1 2
// 0 2 4
// 4 5 5
// 3 5 7