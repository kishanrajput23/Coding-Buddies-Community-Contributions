#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(set<int> adj[], int u, int v)
{
    // directed graph. 
    adj[u].insert(v);
    adj[v].insert(u);
}

// This is a easy question but a tricky one. 
// clique : a subgraph which is fully connected. 
// question: Can we divide the given graph in two components such that there are two cliques. 
// algo: 
// 1. Think in reverse order . 
// 2. If the graph is fully connected so if I would take complement of the given graph. 
// 3. So if the graph could be divided into two cliques , then the complement of that graph must be a bipartite graph. 
// steps: 
// 1. make a complement graph. 
// 2. then check whether the graph is bipartite for given nadj graph. 
// 3. If the nadj graph will be a bipartite graph then the given graph can be resolved into two clique . else not. 
// time complexity: O(V+E)
// space complexity: O(V)
void checkBipartite(set<int> nadj[], vector<int> &color, int src, int &f, int V){
    color[src] = 0;
    for(int u = 0;u<V;u++){
        for(auto v: nadj[u]){
            if(color[u] == 1){
                if(color[v] == -1){
                    color[v] = 0;
                }
                else if(color[v] == 1){
                    f = 0;
                }
            }
            else{
                if(color[v] == -1){
                    color[v] = 1;
                }
                else if(color[v] == 0){
                    f = 0;
                }
            }
        }
    }
}
bool two_clique(set<int> adj[], int V){
    set<int> nadj[V];

    for(int u = 0;u<V;u++){
        for(int v = 0;v<V;v++){
            if(u !=v && adj[u].find(v) == adj[u].end()){
                nadj[u].insert(v);
            }
        }
    }

    for(int i = 0;i<V;i++){
        cout<<i<<"-> ";
        for(auto v: nadj[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    int f = 1;
    vector<int> color(V, -1);
    checkBipartite(nadj, color, 0, f, V);
    return f;
}

int main()
{
    int V = 5;
    set<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 4);
    addEdge(adj, 2, 3);

    bool res = two_clique(adj, V);
    cout<<res;
    return 0;
}