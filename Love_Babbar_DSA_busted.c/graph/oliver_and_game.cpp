#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// This question is not hard but if we are not knowing this concept then we cannot do it. 
// algo: 
// need to know the concept of euler tour
// make a timer , entry time and an exittime array 
// we need to check whether the x is subgraph of y if f == 1 
// else y is a subgraph of x if f == 0
// to check if a if a node is a subgraph of the other node or not. 
// if the entry time is greter for the subragh node and exittime is smaller for the subgraph node so it will be a subgraph. else no. 
// ********** see codelibrary video for better understanding. ********
// time complexity:O(V+E) 
// space compelxity: O(V)
void dfs(vector<int> adj[], int u, vector<int> &entryTime, vector<int> &exitTime, int &timer, vector<int> &vis){
    timer++;
    entryTime[u] = timer;
    vis[u] = 1;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(adj, v, entryTime, exitTime, timer, vis);
        }
    }
    timer++;
    exitTime[u] = timer;
}
bool subgraph(vector<int> adj[], int V, int x, int y){
    vector<int> vis(V, 0);
    vector<int> entryTime(V, 0);
    vector<int> exitTime(V, 0);
    int timer = 0;
    dfs(adj, 0, entryTime, exitTime, timer, vis);
    if(entryTime[y]>entryTime[x] && exitTime[y]<exitTime[x]){
        return true;
    }
    return false;
}
bool oliver_and_game(vector<int> adj[], int n,int f,  int x, int y ){
    if(f == 0){
        if(subgraph(adj, n, x, y)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        if(subgraph(adj,n,y, x)){
            return true;
        }
        else{
            return false;
        }

    }
    return false;
}
int main()
{
    int n, e;
    cin>>n>>e;
    vector<ipair> roads;
    for(int i = 0;i<e;i++){
        int a, b;
        cin>>a>>b;
        roads.push_back({a, b});
    }
    vector<int> adj[n];
    for(int i = 0;i<e;i++){
        adj[roads[i].first].push_back(roads[i].second);
        adj[roads[i].second].push_back(roads[i].first);
    }

    int Q;
    cin>>Q;
    for (int i = 0; i < Q; i++){
        int f, x, y;
        cin>>f>>x>>y;

        bool res = oliver_and_game(adj,n, f, x, y);
        if(res) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
