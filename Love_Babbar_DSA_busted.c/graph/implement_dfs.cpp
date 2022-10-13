#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[], int V)
{
    // for directed graph.
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void printAdjacent(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
        cout << i << "-> ";
        for (auto v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

// Assuming the graph to be connected 
// time complexity: O(V+E)
// space complexity: O(V)
void dfs(vector<int> adj[], int V, int u)
{
    static vector<bool> visited(V, false);
    visited[u] = true;
    cout << u << " ";
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            dfs(adj, V, v);
        }
    }
}

int main()
{
    int V = 3;
    vector<int> adj[V];
    addEdge(0, 1, adj, V);
    addEdge(1, 2, adj, V);
    addEdge(2, 0, adj, V);
    dfs(adj, V, 0);

    return 0;
}