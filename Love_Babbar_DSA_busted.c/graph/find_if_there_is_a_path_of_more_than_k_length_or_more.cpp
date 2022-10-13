#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(vector<ipair> adj[], int u, int v, int wt){
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

// find if there is a path of more than k length or more 
// algo: 
// simply go to all possible paths 
// then find whether we get the sum > = k if true else false
// time compelxity: O(N!)
// space compelxity: O(N)
void dfs(vector<ipair> adj[], int k, int u, int sum, vector<int> &vis, int &f){
    if(sum>= k){
        f = 1;
        return;
    }
    vis[u] = 1;
    for(auto x: adj[u]){
        // auto [v, wt] = x;
        int v = x.first;
        int wt = x.second;
        if(!vis[v]){
            dfs(adj, k, v, sum+ wt, vis, f);
        }
    }
    vis[u] = 0;
}
bool ifPath(vector<ipair> adj[], int V, int k){
    vector<int> vis(V, 0);
    int src = 0;
    int sum = 0;
    int f = 0;
    dfs(adj, k, src, sum, vis, f);
    if(f) return true;

    return false;
}
int main()
{
    int V = 9;
    vector<ipair> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 3, 5, 14);
    int k = 60;
    
    bool res = ifPath(adj, V, k);
    if(res){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
    return 0;
}