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

// assuming the graph is connected 
// time complexity: O(V+E)
// sapce complexity: O(V)
void bfs(vector<int> adj[], int V, int u)
{
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int u = q.front();
        cout << u << " ";
        q.pop();
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
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
    bfs(adj, V, 0);

    return 0;
}