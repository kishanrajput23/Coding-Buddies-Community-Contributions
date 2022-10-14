#include <bits/stdc++.h>
using namespace std;

void addEdge(int u, int v, vector<int> adj[], int V)
{
    // for undirected graph.
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Printing the adjacent of the graph. 
// time complexity: O(V+E)
// space complexity: O(1)
void printAdjacent(vector<int> adj[], int V)
{
    for (int i = 0; i < V; i++)
    {
         cout << i << "-> ";
        for (auto v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}
int main()
{
    int V = 3;
    vector<int> adj[V];
    addEdge(0, 1, adj, V);
    addEdge(1, 2, adj, V);
    addEdge(2, 0, adj, V);
    printAdjacent(adj, V);
    return 0;
}