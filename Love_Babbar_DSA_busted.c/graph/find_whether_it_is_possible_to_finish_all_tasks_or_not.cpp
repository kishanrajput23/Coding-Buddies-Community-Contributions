#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// to find whether it is possible to finish all tasks or not . 
// this is reduced to detect cycle in a directed graph. 
// time complexity: O(V+E)
// space compelxity: O(V)
void possible_tasks_util(vector<int> adj[], int V, int u, vector<int> &visited,  vector<int> &recStack, bool &f){
    recStack[u] = 1;
    visited[u] = 1;
    for(auto v: adj[u]){
        if(!visited[v]){
            possible_tasks_util(adj, V, v, visited, recStack, f);
        }
        else if(visited[v] && recStack[v]){
            f = true;
        }
    }
    recStack[u] = 0;
}
bool possible_tasks(vector<ipair> &prerequisites, int V)
{
    // creating a adjacency list. a
    vector<int> adj[V];
    for(int i = 0;i<prerequisites.size();i++){
        int a = prerequisites[i].second;
        int b = prerequisites[i].first;
        adj[a].push_back(b);
    }

    // ** for debugging** 
    // for (int i = 0; i < V; i++)
    // {
    //     for(auto x: adj[i])
    //     {
    //         cout<<i<<" "<<x<<endl;
    //     }
    // }
    
    // this question is reduced to the detect cycle in a directed graph. 
    // dfs
    vector<int> recStack(V, 0);
    vector<int> visited(V, 0);
    bool f = false;
    for(int i = 0;i<V;i++){
        if(!visited[i]){
            possible_tasks_util(adj, V, i, visited, recStack, f);
        }
    }
    // cout<<"h";
    return f;
}

int main()
{
    int V = 2;
    vector<ipair> prerequisites;
    prerequisites.push_back({1, 0});
    prerequisites.push_back({0, 1});
    bool possible = possible_tasks(prerequisites, V);
    
    if(possible){
        cout<<"It is not possible to finish all tasks as graph contains a cycle"<<endl;
    }
    else{
        cout<<"It is possible to finish all tasks as graph contains does not contains a cycle"<<endl;
    }
    return 0;
}