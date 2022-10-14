#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// This is a good question 
// cheapest flight within k stops 
// algo: 
// the algorithm is similar to that of the dijstra algorithm by using priority queue 
// Just the difference is that here we are said that the number of stops should not be more than k so we had also consider that if stops > k then continue;
// and we had also not visited array as in case of dijstra because there is no need of maintaining that as the question says there cannot be a backedge 
// e.g. : 0-> 1 then there cannot be edge from 1->0 
// Even if we maintain the visited array it will not create any difference 

// I had learnt new about tuple in this question and the new syntax which I need to remember 
// see code library video for better understanding. 
// time complexity: O(V+E)
// space complexity: O(V)
int cheapestFlightKstops(int n, vector<vector<int>> &flights, int src, int des, int k){
    vector<ipair> adj[n];
    for(auto x: flights){
        adj[x[0]].push_back({x[1], x[2]});
    }
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({0, src, 0});
    while(!pq.empty()){
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
    int e = 2;
    vector<vector<int>> flights(e);
    flights[0] = {0, 1, 100};
    flights[1] = {1, 2, 100};

    int src =  0;
    int des = 2;
    int k = 2;
    int res = cheapestFlightKstops(n, flights, src, des, k);
    cout<<res;
    return 0;
}

