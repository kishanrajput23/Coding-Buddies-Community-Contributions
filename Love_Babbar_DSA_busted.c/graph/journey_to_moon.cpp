#include<bits/stdc++.h> 
using namespace std;
// #define int long long 

// this is the journey to the moon 
// there are pairs given of the persons belonging to the same country 
// you need to select the persons not from the same country 
// find all possible persons pair of different country which could go to the moon. 
// algo: 
// this problem is reducible to the: find number of components in an undirected graphs. 
// create a adjacency list from given 2-D array. 
// after finding the number of components in the graphs 
// store all of them in an vector. 
// then find all possible combinations which could be formed 
// see the code for it written by me to understand the algortihm 
// time compelxity: O(V+E)
// space complexity: O(V)
void dfs(vector<int> adj[], vector<int> &vis, int u, int &count){
    vis[u] = 1;
    // cout<<count<<endl;
    count++;
    for(auto v: adj[u]){
        if(!vis[v]){
            dfs(adj, vis, v, count);
        }
    }
}
long long  journey_to_the_moon(vector<int> adj[], int V){
    long long  res = 0;
    vector<int> ans;
    vector<int> vis(V, 0);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            // cout<<i;
            // cout<<"hi"<<endl;
            int count = 0;
            dfs(adj, vis, i, count);
            // cout<<count<<" ";
            // res *= count;
            ans.push_back(count);
        }
    }
    // cout<<ans.size();
    // for(int i = 0;i<ans.size();i++){
    //     cout<<ans[i]<<" ";
    // }
    // cout<<endl;
    vector<int> sum(ans.size(), 0);
    sum[0] = ans[0];
    // cout<<sum[0]<<" ";
    for(int i = 1;i<ans.size();i++){
        sum[i] = sum[i-1]+ ans[i];
        // cout<<sum[i]<<" ";
    }
    // cout<<endl;
    for(int i = 1;i<ans.size();i++){
        int j = i-1;
        res += ans[i]*sum[j];
    }
    return res;
}
int32_t main(){
    // input 
    int n, p;
    cin>>n>>p;
    int arr[p][2];
    for(int i = 0;i<p;i++){
        int a, b;
        cin>>a>>b;
        arr[i][0] = a;
        arr[i][1] = b;
    }

    // creating a adj list from given array 
    vector<int> adj[n];
    for(int i = 0;i<p;i++){
        adj[arr[i][0]].push_back(arr[i][1]);
        adj[arr[i][1]].push_back(arr[i][0]);
    }
    // cout<<"i";
    // for(int i = 0;i<n;i++){
    //     cout<<i<<"->";
    //     for(auto x: adj[i]){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    long long  number_of_possiblities = journey_to_the_moon(adj, n);
    cout<<number_of_possiblities<<endl;
    return 0;
}