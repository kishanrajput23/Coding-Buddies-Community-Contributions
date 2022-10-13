#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

int cheapestFlightKstops(int n, vector<vector<int>> &flights, int src, int des, int k){
    vector<ipair> adj[n];
    for(auto x: flights){
        adj[x[0]].push_back({x[1], x[2]});
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, src, 0});
    while(!pq.empty()){
        // tuple<int, int, int> t = pq.top();
        // int cost = t.first;
        // int u = t.second;
        // int stops= t.third;
        auto [cost, u, stops] = pq.top();
        pq.pop();
        if(u == des) return cost;
        if(stops> k) continue;
        for(auto x: adj[u]){
            auto [v, wt] = x;
            pq.push(make_tuple(cost+ wt, v, stops+ 1));
        }
    }
    return -1;
}
int main(){
    int n = 3;
    vector<vector<int>> flights(n);
    flights[0] = {0, 1, 100};
    flights[1] = {1, 2, 100};

    int src =  0;
    int des = 2;
    int k = 2;
    int res = cheapestFlightKstops(n, flights, src, des, k);
    cout<<res;
    return 0;
}

