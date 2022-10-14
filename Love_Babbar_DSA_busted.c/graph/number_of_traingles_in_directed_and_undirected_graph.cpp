#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(set<int> adj[], int u, int v)
{
    // directed graph. 
    adj[u].insert(v);
    // adj[v].insert(u);
}

// It's an easy but a tricky question to do 
// caculate number of triangles in a directed and undirected graph. 
// algo: 
// check for all triplets of the vertices i, j, k
// if there is an edge from i to j , j to k and k to i. 
// then increment the count pointer. 
// for undirected graph return count/6 due to repitions 
// for directed graph return count/3 due to repitions. 
// see gfg article for better understanding. 
// time complexity: O(V^3)
// space complexity: O(V)
int triangles_in_directed_graph(set<int> adj[], int V){
    int count = 0;
    for(int i = 0;i<V;i++)
        for(int j = 0;j<V;j++)
            for(int k = 0;k<V;k++)
                if(adj[i].find(j) != adj[i].end() && adj[j].find(k) != adj[j].end() && adj[k].find(i) != adj[k].end())
                    count++;
    
    return count/3;
} 

int triangles_in_undirected_graph(set<int> adj[], int V){
    int count = 0;
    for(int i = 0;i<V;i++)
        for(int j = 0;j<V;j++)
            for(int k = 0;k<V;k++)
                if(adj[i].find(j) != adj[i].end() && adj[j].find(k) != adj[j].end() && adj[k].find(i) != adj[k].end())
                    count++;
    
    return count/6;
}
int main()
{
    int V = 3;
    set<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    // addEdge(adj, 3, 4);
    // addEdge(adj, 4, 5);
    // addEdge(adj, 5, 6);

    int triangles = triangles_in_directed_graph(adj, V);
    cout<<triangles<<endl;
    return 0;
}