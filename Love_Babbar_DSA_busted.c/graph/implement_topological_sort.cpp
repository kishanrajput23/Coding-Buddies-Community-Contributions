#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(int u, int v, vector<int> adj[], int V)
{
    adj[u].push_back(v);
}

// appraoch 1:
// by bfs.
// this is called as topological sort
// the topological sort is only valid for DAG
// bfs : called as kahns algorithm.
// time complexity: O(V+E)
// space compelxity: O(V)
void topological_sort_bfs(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto x : adj[i])
        {
            int v = x;
            indegree[v]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for (auto v : adj[u])
        {
            indegree[v]--;
            if (indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }
}

// approach 2:
// by dfs
// time complexity: O(V+E)
// space complexity: O(V)

void topological_sort_dfs_rec(int u, vector<int> adj[], int V, stack<int> &s, vector<int> &visited)
{

    visited[u] = 1;
    for (auto v : adj[u])
    {
        if (!visited[v])
        {
            topological_sort_dfs_rec(v, adj, V, s, visited);
        }
    }

    s.push(u);
}
void topological_sort_dfs(vector<int> adj[], int V)
{

    vector<int> visited(V, 0);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            int count = 1;
            topological_sort_dfs_rec(i, adj, V, s, visited);
        }
    }

    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        cout <<temp<<" ";
    }


}
int main()
{
    int V = 11;
    vector<int> adj[V];

    addEdge(0, 1, adj, V);
    addEdge(1, 3, adj, V);
    addEdge(1, 4, adj, V);
    addEdge(1, 5, adj, V);
    addEdge(2, 3, adj, V);
    addEdge(2, 9, adj, V);
    addEdge(2, 8, adj, V);
    addEdge(3, 6, adj, V);
    addEdge(4, 6, adj, V);
    addEdge(4, 8, adj, V);
    addEdge(5, 8, adj, V);
    addEdge(6, 7, adj, V);
    addEdge(7, 8, adj, V);
    addEdge(8, 10, adj, V);

    topological_sort_bfs(adj, V);
    cout << endl;
    topological_sort_dfs(adj, V);
    return 0;
}