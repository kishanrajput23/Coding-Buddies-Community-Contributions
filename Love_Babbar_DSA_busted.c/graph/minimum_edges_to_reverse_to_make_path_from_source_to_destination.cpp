#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(vector<int> adj[], int u, int v){
    // for directed graph. 
    adj[u].push_back(v);
}

// This is a simple question but a tricky one . 
// see gfg article for better understanding. 
// algo:
// create a copy of graph with undirected in nature 
// keeping the old edges with wt as 0 , 
// and keeping the new edges with wt as 1, 
// apply dijstra algorithm. 
// see geeks for geeks article for checking the approach. 
// time complexity: O(VlogE)
// space complexity: O(V)
int minimumEdgesToReverse(vector<int> adj[], int V, int src, int des){
    // creating a new adjacency list 
    if(src == des){
        return 0;
    }
    vector<ipair> nadj[V];
    for(int i = 0;i<V;i++){
        for(auto u: adj[i]){
            nadj[i].push_back({u, 0});
            nadj[u].push_back({i, 1});
        }
    }

    // applying dijstra 
    vector<int> setMST(V, 0);
    priority_queue<ipair> pq;
    pq.push({src, 0});
    int res;
    while(!pq.empty()){
        auto a = pq.top();
        int u = a.second;
        int dis = a.first;
        pq.pop();
        setMST[u] = 1;
        if(u == des){
            res = dis;
            break;
        }
        for(auto x: nadj[u]){
            int v = x.first;
            int wt = x.second;
            if(!setMST[v]){
                pq.push({dis+wt, v});
            }
        }
    }
    return res;
}
int main()
{
    int V = 7;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 6, 3);
    addEdge(adj, 6, 5);
    addEdge(adj, 4, 5);
    addEdge(adj, 4, 1);

    int src = 0;
    int des = 6;
    int res = minimumEdgesToReverse(adj, V, src, des);
    cout<<res<<endl;
    return 0;
}