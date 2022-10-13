#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(vector<int> adj[], int u, int v){
    // for directed graph. 
    adj[u].push_back(v);
}

// kosaraju algorithm 
// It is for strongly connected components 
// time complexity: O(V+E)
// space complexity: O(V)
void dfs1(vector<int> adj[], int V, vector<int> &vis, int u, stack<int> &st){
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs1(adj, V, vis, v, st);
        }
    }
    st.push(u);
}

void reverseEdges(vector<int> adj[], int V, vector<int> rev[]){
    for(int u = 0;u<V;u++){
        for(auto v: adj[u]){
            rev[v].push_back(u);
        }
    }
}

void dfs2(vector<int> adj[], int V, int u, vector<int> &vis){
    vis[u] = 1;
    cout<<u<<" ";
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs2(adj, V, v, vis);
        }
    }
}
void kosaraju_algo(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    stack<int> st;

    // doing first dfs to store all the elements in a stack. 
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfs1(adj, V, vis, i, st);
        }
    }

    // reversing all the edge directions. 
    vector<int> rev[V];
    reverseEdges(adj, V, rev);

    for(int i = 0;i<V;i++) vis[i]= 0;
    // then again doing dfs and printing all the strongly connected components 
    while(!st.empty()){
        int u = st.top();
        st.pop();
        if(!vis[u]){
            dfs2(rev, V, u, vis);
            cout<<endl;
        }
    }
}
int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);
    addEdge(adj, 3, 4);
    kosaraju_algo(adj, V);
    return 0;
}