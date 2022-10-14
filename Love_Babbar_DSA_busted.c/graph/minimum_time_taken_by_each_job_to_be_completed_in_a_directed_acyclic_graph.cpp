#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

void addEdge(int u, int v, vector<int> adj[], int V)
{
    adj[u].push_back(v);
}


// this question is similar to that of the topological sort . 
void util(int u, vector<int> adj[], int V, vector<int> &visited, stack<int> &s, map<int, int> &m, int count)
{
    m[u] = count;
    visited[u] = 1;
    for(auto v: adj[u]){
        if(!visited[v]){
            util(v, adj, V, visited, s, m, count+1);
        }
    }
    s.push(u);
}
void minimum_time_taken_by_job(vector<int> adj[], int V)
{
    map<int, int> m;
    stack<int> s;
    vector<int> visited(V, 0);
    for(int i =0;i<V;i++){
        if(!visited[i]){
            int count = 1;
            util(i, adj, V, visited, s, m, count);
        }
    }

    // while(!s.empty()){
    //     int temp = s.top();
    //     s.pop();
    //     cout<<temp<<" ";
    // }

    for(auto x: m){
        cout<<x.first<<"->"<<x.second<<endl;
    }
}

int main()
{
    int V = 11;
    vector<int> adj[V];

    addEdge(0, 1, adj, V);
    addEdge(1, 3, adj, V);
    addEdge(1, 4, adj, V);
    addEdge(1, 5, adj, V);
    addEdge(2, 3, adj, V);
    addEdge(2, 9, adj, V);
    addEdge(2, 8, adj, V);
    addEdge(3, 6, adj, V);
    addEdge(4, 6, adj, V);
    addEdge(4, 8, adj, V);
    addEdge(5, 8, adj, V);
    addEdge(6, 7, adj, V);
    addEdge(7, 8, adj, V);
    addEdge(8, 10, adj, V);

    minimum_time_taken_by_job(adj, V);
    return 0;
}