#include <iostream>
#include <climits>
using namespace std;

int myMin2(int num1, int num2)
{
    if (num1 <= num2)
        return num1;
    else
        return num2;
}
int n = 4;

int dp[16][4];

// Adj Matrix which defines the graph
int dist[10][10] = {
    {0, 20, 42, 25},
    {20, 0, 30, 34},
    {42, 40, 0, 10},
    {25, 34, 10, 0}};

// if all the cities have been visited
int VISITED_ALL = (1 << n) - 1;

int tsp(int mask, int pos)
{
    if (mask == VISITED_ALL)
        return dist[pos][0];

    // Lookup case
    if (dp[mask][pos] != -1)
        return dp[mask][pos];

    int ans = INT_MAX;

    // TRy to goto an unvisited city
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            // ORRing with mask
            // 0010
            // 0001
            // -----
            // 0011
            // -----
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = myMin2(ans, newAns);
        }
    }

    return dp[mask][pos] = ans;
}
int main()
{
    for (int i = 0; i < (1 << n); i++)
        for (int j = 0; j < n; j++)
            dp[i][j] = -1;

    // Initial Mask = 0001
    cout << "Minimum Wright Hamiltonian Path costs " << tsp(1, 0) << endl;
    return 0;
}