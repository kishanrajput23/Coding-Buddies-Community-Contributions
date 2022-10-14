#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// void addEdge(set<int> adj[], int u, int v){
//     adj[u].insert(v);
//     adj[v].insert(u);
// }

// // Before doing the travelling salesman problem you need to first do 
// // whether a hamiltonian cycle exists in a graph or not . 
// // this code for checking whether the hamiltonian cycle exists or not is written by me 
// // not seen from anywhere 
// // Algo; 
// // do dfs 
// // while doing dfs . 
// // checking for the conditions for the hamiltonian cycle to exist 
// // if the visited array is completely visited and the adjacent points to the src of it . then a hamiltonian cycle exists. 
// // if f == 2 || 0 it means that hamiltonian cycle does not exist. 
// // if all the adjacent are visited , as we cannot repeat any vertex so there would be no hamiltonian cycle. 
// // time complexity: O((V+E)*V)
// // space compelxity: o(V)
// //** DRAWBACK: This function written by me cannot print the possible number of hamiltonian cycles**

// int f = 0;
// void dfs(set<int> adj[], int u, vector<int> &vis)
// {
//     static int src = u;
//     vis[u] = 1;
//     int visc = 0;
//     for(auto v: adj[u]){
//         if(f == 2 || f == 1){
//             return;
//         }
//         if(!vis[v]){
//             dfs(adj, v, vis);
//         }
//         else if(vis[v]){
//             visc++;
//             int count = 0;
//             for(int i = 0;i<vis.size();i++){
//                 if(vis[i] == 0){
//                     break;
//                 }
//                 else{
//                    count++;
//                 }
              
//             }
//             if(count == vis.size() && v== src){
//                 f = 1;
//                 return;
//             }
//         }
//         if(f == 2 || f == 1){
//             return;
//         }
//     }
//     if(f == 2 || f == 1){
//         return;
//     }
//     if(visc == adj[u].size()){
//         f = 2;
//         return;
//     }
// }


// // This code finds all the hamiltonian cycles and print them. 
// // This is for hamiltonian cycles 
// // see abdul bari video for understanding the logic 
// // I had code this myself with the help of adj list representation. 
// // time complexity: O((V+E)*V)
// // space compelxity: O(V)
// int src = 0;
// void printIt(vector<int> &vis){
//     for (int i = 0; i < vis.size(); i++)
//     {
//         cout<<vis[i]<<" ";
//     }
//     cout<<endl;  
// }
// void hamiltonian(set<int> adj[], int j, vector<int> &vis){
//     for(auto u: adj[vis[j-1]]){
//         if(j == vis.size()){
//             if(u == src){
//                 printIt(vis);
//                 return;
//             }
//         }
//         int f = 0;
//         for(int i = 0;i<=j-1;i++){
//             if(u == vis[i]){
//                 f = 1;
//                 break;
//             }
//         }
//         if(f==0){
//             vis[j] = u;
//             j++;
//             hamiltonian(adj, j, vis);
//             j--;
//         }
//     }
// }


// int main()
// {
//     int V = 5;
//     set<int> adj[V];
//     addEdge(adj, 0, 1);
//     addEdge(adj, 1, 2);
//     addEdge(adj, 2, 3);
//     addEdge(adj, 3, 1);
//     addEdge(adj, 4, 3);
//     addEdge(adj, 0, 4);
//     addEdge(adj, 0, 2);


//     vector<int> vis(V, 0);
//     // dfs(adj, 0, vis);
//     // cout<<f<<endl;
//     // if(f ==0 || f== 2){
//     //     cout<<"No hemiltonian cycle exists"<<endl;
//     // }
//     // else {
//     //     cout<<"The hamiltonian cycle exists"<<endl;
//     // }
//     int j = 1;
//     hamiltonian(adj, j, vis);
//     return 0;
// }



// Now talking about TSP : 
// travelling salesman problem. 
// This is a NP-hard problem 
// Not yet the polynomial time complexity have been discovered for it. 
// so it will have exponential time complexity 
// This could little reduced by dp, approach formula for it is written in the copy notes no code is available for it . 
// see abdul bari sir video on you tube to see the dp based formula 
// time complexity: O(factorial(n)) === O(n^n)
// space complexity: approximately exponential 
// go to all possible paths and find the minimum 
void tsp(vector<vector<int>> &g, int currmin, int &fmin, int V, int count, vector<int> &vis, int u){
    vis[u] = 1;
    count++;
    // cout<<count<<endl;
    if(count == V){
        fmin = min(fmin, currmin+ g[u][0]);
        vis[u] = 0;
        return;
    }
    for(int v = 0;v<V;v++){
        if(g[u][v] != 0 and !vis[v]){
            tsp(g, currmin+g[u][v] , fmin, V, count, vis, v);
        }
    }
    vis[u] = 0;
}
int main(){
    vector<vector<int>> g = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };
    int V = g.size();
    int currmin = 0;
    int fmin = INT_MAX;
    vector<int> vis(V, 0);
    int src = 0;
    int count = 0;
    tsp(g, currmin, fmin, V, count, vis, src);
    cout<<fmin;
}