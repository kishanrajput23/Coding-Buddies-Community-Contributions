#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;
void addEdge(int u, int v, int wt,  vector<ipair> adj[], int V)
{
    // for undirected graph. 
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

void dijstraAlgo(vector<ipair> adj[], int V)
{
    vector<int> value(V, inf);
    value[0] = 0;
    vector<int> setMST(V, 0);
    vector<int> parent(V, -1);
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    pq.push({0, 0});
    for(int i =0;i<V-1;i++)
    {
        int currd = pq.top().first;
        int u = pq.top().second;
        setMST[u] = 1;
        pq.pop();
        for(auto x: adj[u])
        {
            int v = x.first;
            int wt = x.second;
            if(!setMST[v] and value[u] + wt <value[v])
            {
                value[v] = value[u] +wt;
                parent[v] = u;
                pq.push({value[v], v});
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        cout<<i<<" "<<value[i];
        cout<<endl;
    }
    
}
int main()
{
    int V = 3;
    vector<ipair> adj[V];
    addEdge(0, 1, 1, adj, V);
    addEdge(1, 2, 2, adj, V);

    dijstraAlgo(adj, V);
    return 0;
}