#include <bits/stdc++.h>
using namespace std;

// need to make minimum operations to make the given graph connected , an undirected graph is given. 
// algo
// count total edges 
// check if total edges are less than v-1 if return -1 else move ahead in the code
// make a adjacency list. 
// doing dfs and counting number of connected components. 
// then simply return c-1. 
void dfs(int u, int n, vector<int> &vis, vector<int> adj[])
{
    vis[u] = 1;
    for (auto v : adj[u])
    {
        if (!vis[v])
        {
            dfs(v, n, vis, adj);
        }
    }
}
int makingConnected(int n, vector<vector<int>> &v)
{
    int totalEdges = v.size();
    if (totalEdges < (n - 1))
    {
        return -1;
    }
    vector<int> adj[n];
    for (int i = 0; i < v.size(); i++)
    {
        // for undirected graph. 
        adj[v[i][0]].push_back(v[i][1]);
        adj[v[i][1]].push_back(v[i][0]);
    }
    // cout<<"hi";
    vector<int> vis(n, 0);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            c++;
            dfs(i, n, vis, adj);
        }
    }
    return (c - 1);
}
int main()
{
    int n = 4;
    int edges = 3;
    vector<vector<int>> v(edges);
    // cout<<"working";
    v[0].push_back(0);
    v[0].push_back(1);
    v[1].push_back(1);
    v[1].push_back(2);
    v[2].push_back(0);
    v[2].push_back(2);

    int res = makingConnected(n, v);
    cout <<"Minimum number of operations to make nodes connected is : "<< res;
    return 0;
}