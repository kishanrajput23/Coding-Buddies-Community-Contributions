#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[], int V)
{
    // for directed graph.
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

// detect cycle in directed graph using dfs
// If a back edge exists in a dfs tree then the graph will be containing a cycle .
// time complexity: O(V+E)
// space complexity: O(V)
void dfsUtil(vector<int> adj[], int V, int u, vector<int> &s, vector<int> &visited, int &f)
{
    visited[u] = 1;
    s[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            dfsUtil(adj, V, v, s, visited, f);
        }
        else if (s[v])
        {
            f = 1;
        }
    }
    s[u] = 0;
}

bool detect_cycle_dfs(vector<int> adj[], int V)
{
    vector<int> s(V, 0);
    vector<int> visited(V, 0);
    int f = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            dfsUtil(adj, V, i, s, visited, f);
        }
    }
    return f;
}

// detect cycle using bfs
// time complexity: O(V+E)
// space complexity: O(V)
bool detect_cycle_bfs(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);
    int f = 1;
    queue<int> q;
    int count = 0;
    // calculating number of indegree
    for (int i = 0; i < V; i++)
    {
        for (auto v : adj[i])
        {
            indegree[v]++;
        }
    }

   // counting 0 indegree vertices and pushing them into the queue. 
    for (int i = 0; i < V; i++)
    {
        if (!indegree[i])
        {
            count++;
            q.push(i);
        }
    }

    // further calculations
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v: adj[u])
        {
            indegree[v]--;
            if(!indegree[v])
            {
                count++;
                q.push(v);
            }
        }
    }
    
    if(count == V)
    {
        f = 0;
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
    cout << detect_cycle_bfs(adj, V);

    return 0;
}