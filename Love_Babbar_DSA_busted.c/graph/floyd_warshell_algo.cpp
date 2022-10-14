#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// this finds the shortest path for all possible pairs
// time complexity: O(V^3)
// space compelxity: O(V^2)
void floyd_warshell(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<vector<int>> dis(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            dis[i][j] = adj[i][j];

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dis[i][k] != inf and dis[k][j] != inf and (dis[i][k] + dis[k][j] < dis[i][j]))
                    dis[i][j] = dis[i][k] + dis[k][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (dis[i][j] < 0)
                cout << "-ve edge weight cycle detected" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    vector<vector<int>> adj = {
        {0, 8, inf, 1},
        {inf, 0, inf, inf},
        {4, 1, 0, inf},
        {inf, 2, 9, 0}};

    floyd_warshell(adj);
    return 0;
}