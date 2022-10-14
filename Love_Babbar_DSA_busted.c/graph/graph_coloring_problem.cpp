#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(set<int> adj[], int u, int v){
    adj[u].insert(v);
    adj[v].insert(u);
}
// I will come back to this question later on. p
// this code is written by me but failing some test cases 
void dfsUtil(set<int> adj[], int u, vector<int> &vis, vector<int> &vcolors, int number_of_colors){
    vis[u] = 1;
    vector<int> gcolors(number_of_colors, 0);
    for(auto v: adj[u]){
        if(vcolors[v] != inf){
            gcolors[vcolors[v]] = 1;
        }
    }
    for(int i = 0;i< number_of_colors;i++){
        if(gcolors[i] == 0){
            // cout<<i<<" ";
            vcolors[u] = i;
            break;
        }
    }

    for(auto v: adj[u]){
        if(!vis[v]){
            dfsUtil(adj, v, vis, vcolors, number_of_colors);
        }
    }
}
bool graphColoring(set<int> adj[], int V, int number_of_colors){
    vector<int> vis(V, 0);
    vector<int> vcolors(V, inf);

    for(int i = 0;i<V;i++){
        if(!vis[i]){
            dfsUtil(adj, 0, vis, vcolors, number_of_colors);
        }
    }
    for(int i = 0;i<vcolors.size();i++){
        cout<<vcolors[i]<<" ";
    }
    cout<<endl;

    for(int i = 0;i<vcolors.size();i++){
        if(vcolors[i] == inf){
            return false;
        }
    }
    return true;
}


int main()
{
    int V = 4;
    set<int> adj[V];
    addEdge(adj, 0, 3);
    addEdge(adj, 3, 2);
    addEdge(adj, 2, 1);
    // addEdge(adj, 3, 0);
    // addEdge(adj, 0, 2);
    // addEdge(adj, 2, 3);
    // addEdge(adj, 2, 4);

    int numberofcolors = 3;
    int minimumcolors = graphColoring(adj, V, numberofcolors);
    cout<<minimumcolors<<endl;

    return 0;
}