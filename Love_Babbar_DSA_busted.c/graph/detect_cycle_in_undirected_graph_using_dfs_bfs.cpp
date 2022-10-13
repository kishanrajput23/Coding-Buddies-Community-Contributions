#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[], int V)
{
    // for undirected graph.
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// detect cycle in an undirected graph  with the help of dfs
// time complexity: O(V+E)
// space complexity: O(V)
void dfsUtil(vector<int> adj[], int V, int u, vector<int> &visited, int &f, int &parent)
{
    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            dfsUtil(adj, V, v, visited, f, u);
        }
        else if (parent != v)
        {
            f = 1;
        }
    }
}

bool detect_cycle_dfs(vector<int> adj[], int V)
{
    vector<int> visited(V, 0);
    int f = 0;
    int parent = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsUtil(adj, V, i, visited, f, parent);
        }
    }
    return f;
}

// Detect cycle in an undirected graph with the help of bfs
// time complexity: O(V+E)
// space complexity: O(V)
void bfsUtil(vector<int> adj[], int V, int u, vector<int> &visited, int &parent, int &f)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push(v);
            }
            else if (parent != v)
            {
                f = 1;
            }
        }
        parent = u;
    }
}

bool detect_cycle_bfs(vector<int> adj[], int V)
{
    vector<int> visited(V, 0);
    int f = 0;
    int parent = -1;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            bfsUtil(adj, V, i, visited, parent, f);
        }
    }
    return f;
}


int main()
{
    int V = 3;
    vector<int> adj[V];
    addEdge(0, 1, adj, V);
    addEdge(1, 2, adj, V);
    // addEdge(2, 0, adj, V);
    // cout << detect_cycle_dfs(adj, V);
    cout<<detect_cycle_bfs(adj, V);

    return 0;
}