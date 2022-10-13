#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(vector<int> adj[], int u, vector<int> &vis){
    vis[u] = 1;
    for(auto v: adj[u])
    {
        if(!vis[v])
        {
            dfs(adj, v, vis);
        }
    }
}

// see from notes 
// time complexity: O(V+E)
// space compleixty: O(V)
int eulerity_check(vector<int> adj[], int V){
    vector<int> degree(V, 0);
    for(int i = 0;i<V;i++){
        for(auto v: adj[i]){
            degree[i]++;
        }
    }
    int f = 0;
    vector<int> vis(V, 0);
    for(int i = 0;i<V;i++){
        if(degree[i]>0){
            f = 1;
            dfs(adj, i, vis);
        }
    }
    if(f == 0) return 2;
    for(int i = 0;i<V;i++)
        if(!vis[i] && degree[i]>0)
            return 0;

    int oddcount = 0;
    for(int i = 0;i<V;i++){
        if(degree[i] %2 !=0)
            oddcount++;
    }

    if(oddcount == 0) return 2;
    else if(oddcount == 2) return 1;

    return 0;
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);
    addEdge(adj, 3, 4);
    addEdge(adj, 0, 4);

    int res = eulerity_check(adj, V);

    if(res == 1)
        cout<<"Semi eulerian graph"<<endl;
    else if(res == 2)
        cout<<"Eulerian graph"<<endl;
    else 
        cout<<"non-eulerian graph"<<endl;
    return 0;
}