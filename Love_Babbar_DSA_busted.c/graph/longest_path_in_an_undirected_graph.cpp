#include<bits/stdc++.h> 
using namespace std;
#define minf INT_MIN
typedef pair<int, int> ipair;
void addEdge(vector<ipair> adj[], int u, int v, int wt){
    adj[u].push_back({v, wt});
}

// the problem is exactly same as shortest path in a DAG 
// just the difference is in line of code
//  dis[v] = max(dis[v], dis[u] + wt)
// put all distances as minf
// Assuming the source to be zero always 
// time complexity: O(V+E)
// space complexity: O(V)
void topological_sort(vector<ipair> adj[], int V, int u, stack<int> &s, vector<int> &vis){
    vis[u] = 1;
    for(auto x: adj[u]){
        int v = x.first;
        if(!vis[v]){
            topological_sort(adj, V, v, s, vis);
        }
    }
    s.push(u);
}
void longest_path_in_a_dag(vector<ipair> adj[], int V){
    stack<int> s;
    vector<int> vis(V, 0);
    // assuming the given graph is a single connected graph. 
    topological_sort(adj, V, 0, s, vis);
    vector<int> dis(V, minf);
    dis[0] = 0;
    while(!s.empty()){
        int u = s.top();
        s.pop();
        for(auto x: adj[u]){
            int v = x.first;
            int wt = x.second;
            dis[v] = max(dis[v], dis[u]+ wt);
        }
    }
    for(int i = 0;i<dis.size();i++) cout<< dis[i]<<" ";
}
int main(){
    int V, E;
    cin>>V>>E;
    vector<ipair> adj[V];
    for(int i = 0;i<E;i++){
        int u, v, wt;
        cin>>u>>v>>wt;
        addEdge(adj, u, v, wt);
    }
    longest_path_in_a_dag(adj, V);
    return 0;
}