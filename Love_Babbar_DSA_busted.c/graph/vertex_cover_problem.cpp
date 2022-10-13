#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(set<int> adj[], int u, int v)
{
    // undirected graph. 
    adj[u].insert(v);
    adj[v].insert(u);
}

// Given an undirected graph 
// Create a minimum subset of vertices such that all the edges are included(adjacent to them). 
// This is a NP- complete problem 
// There are three appraoches and many more to solve this problem 

// approach 1:
// create all possible subsets and check 
// for which we could have the answer with minimum number of vertices 
// time complexity: O(2^N)

// appraoch 2: greedy 
// this is seen from 'santhoshini mariyala' you tube channel 
// This is an approximate algorithm and fails many times 
// go to this link to see where this algo fails: https://www.slideshare.net/GajanandSharma1/vertex-cover-problem
//algo: 
// create a degree vector of all vertices . 
// find the vertex with maximum degree put that into the subset of vertices 
// and update the degree of all it's adjacent by 1. 
// time complexity: O(V+E)

// approach 3: 
// this approach is given on gfg dry run for understanding. 
// This is much better than appraoch 2, but also fails many test cases 
// algo: 
// 1) Initialize the result as {}
// 2) Consider a set of all edges in given graph.  Let the set be E.
// 3) Do following while E is not empty
// ...a) Pick an arbitrary edge (u, v) from set E and add 'u' and 'v' to result
// ...b) Remove all edges from E which are either incident on u or v.
// 4) Return result 
// time complexity: O(V+E)
// space complexity:O(V)
void vertexCoverProblem(set<int> adj[], int V){
    vector<int> vis(V, 0);
    for(int u = 0;u<V;u++){
        if(!vis[u]){
            for(auto v: adj[u]){
                if(!vis[v]){
                    vis[u] = 1;
                    vis[v] = 1;
                    break;
                }
            }
        }
    }

    for(int i = 0;i<V;i++){
        if(vis[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}

int main()
{
    int V = 7;
    set<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);

    vertexCoverProblem(adj, V);
    return 0;
}