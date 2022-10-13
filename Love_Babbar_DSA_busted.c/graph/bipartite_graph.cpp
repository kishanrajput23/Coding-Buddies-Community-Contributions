#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(vector<int> adj[], int u, int v){
    // for undirected graph. 
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// to check whether a given graph is bipartite or not . 
// bipartite : if we maintain two sets and there are vertices in the sets and there is no edge belonging to the same set of pair of vertices 
// see pep coding video for understanding what is bipartite if you forget later 
// but the logic and code should be from code library sir video 
// this code is written by me .
// Observation: 
// If a graph does not contain any cycle then the graph is always a bipartite graph. 
// If a graph contains a cycle then there are two possiblitites: 
// firstly see all possible cycles in the given graph 
// if the graph contains an odd cycle then the graph cannot be a bipartite graph . 
// else the graph is a bipartite graph for all even cycles  
// algo: 
// 1. solved by graph coloring . coloring the graph with 2 colors if it is possible to color the graph then it's a bipartite graph else not . 
// 2. do either bfs or dfs then normally color the graph by maintaing a color array and seeing that no adjacent should have the same color 
// 3. If the adjacent has the same color then simply put counter f = 0 no bipartite graph exists. 

//time complexity: O(V+E)
// space complexity: O(V+E)
// I had done here by bfs. 
//****** same for dfs *****
// e.g. 
//         0 
//        /  \
//       1    2
//       |    | 
//       3----4   No it's not a bipartite graph. 

//         0
//        / \
//       1   2
//       |   |    Yes it's a bipartite graph. 
//       3   4
//        \  /
//         5
int check(vector<int> adj[], int V){
    vector<int> vis(V, 0);
    vector<int> color(V, inf);
    queue<int> q;

    int f = 1;
    // this outer loop is to check for disconnected graphs only . 
    for(int i = 0;i<V;i++){
        if(!vis[i]){
                q.push(i);
                color[i] = 0;
                vis[i] = 1;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto v: adj[u]){
                    if(!vis[v]){
                        vis[v] = 1;
                        q.push(v);
                        if(color[u] == 0){
                            color[v] = 1;
                        }
                        else{
                            color[v] = 0;
                        }
                    }
                    else if(vis[v] && color[u] == color[v]){
                        f = 0;
                        return f;
                    }
                }
            }
        }
    }
    
    return f;
}
int main()
{
    int V = 9;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 4, 5);
    addEdge(adj, 3, 5);
    addEdge(adj, 6, 7);
    addEdge(adj, 8, 7);
    addEdge(adj, 8, 6);

    int bipartite_graph = check(adj, V);
    cout<<bipartite_graph<<endl;
    return 0;
}