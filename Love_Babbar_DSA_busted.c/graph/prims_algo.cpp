#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// This is the prims algorithm 
// there are two ways to implement the prims algorithm 
// first: brute force using adj matrix and normal value array 
// time complexity: O(V**2)
// space complexity: O(V)

// second: efficient , the above approach can be made efficient by using adj list and priority queue 
// along with the value array 
// time complexity: O(ElogV)
// space complexixty: O(V)
void addEdge(int u, ipair x, vector<ipair> adj[]){
    int v = x.first;
    int wt = x.second;
    // for undirected graph. 
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}

void prims_algo(vector<ipair> adj[], int V){
    vector<int> value(V, inf);
    value[0] = 0;
    vector<int> setMST(V, 0);
    vector<int> parent(V, -1);
    // first : value , second: vertex 
    priority_queue<ipair, vector<ipair>, greater<ipair>> pq;
    pq.push({0, 0});
    for(int i = 0;i<V-1;i++){
        // int wt = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        setMST[u] = 1;
        for(auto x: adj[u]){
            int v = x.first;
            int wt = x.second;
            if(!setMST[v] and wt< value[v]){
                value[v] = wt;
                parent[v] = u;
                pq.push({wt, v});
            }
        }
    }

    for(int i = 0;i<V;i++){
        cout<<i<<"->"<< parent[i]<<endl;
    }
}
int main()
{
    int V = 3;
    vector<ipair> adj[V];
    addEdge(0, {1, 20}, adj);
    addEdge(0, {2, 17}, adj);
    addEdge(1, {2, 15}, adj);

    prims_algo(adj, V);
    return 0;
}