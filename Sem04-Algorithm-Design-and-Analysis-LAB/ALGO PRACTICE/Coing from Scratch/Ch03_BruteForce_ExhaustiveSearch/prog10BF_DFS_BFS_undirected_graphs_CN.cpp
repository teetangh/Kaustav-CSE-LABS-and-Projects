#include <iostream>
#include <queue> // for BFS only
using namespace std;

void printDFS(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
            continue;
        if (edges[sv][i] == 1)
        {
            if (visited[i])
                continue;
            printDFS(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> pendingVertices;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    pendingVertices.push(sv);
    visited[sv] = true;

    while (!pendingVertices.empty())
    {
        // Earlier Versions
        /* From Stack Overflow
        One might wonder why pop() returns void, instead of value_type. That is, why must one use front() and pop() to examine and remove the element at the front of the queue, instead of combining the two in a single member function? In fact, there is a good reason for this design. If pop() returned the front element, it would have to return by value rather than by reference: return by reference would create a dangling pointer. Return by value, however, is inefficient: it involves at least one redundant copy constructor call. Since it is impossible for pop() to return a value in such a way as to be both efficient and correct, it is more sensible for it to return no value at all and to require clients to use front() to inspect the value at the front of the queue.
        */
        // int currentVertex = pendingVertices.pop();

        // Newerversion
        int currentVertex = pendingVertices.front();
        pendingVertices.pop();

        cout << currentVertex << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currentVertex)
                continue;
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    delete[] visited;
}

int main(int argc, char const *argv[])
{
    int n;
    int e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    cout << "DFS" << endl;
    printDFS(edges, n, 0, visited);
    cout << "BFS" << endl;
    printBFS(edges, n, 0);

    return 0;
}
// // Sample IO
// 4
// 3
// 0 2
// 2 1
// 1 3
// DFS
// 0
// 2
// 1
// 3
// BFS
// 0
// 2
// 1