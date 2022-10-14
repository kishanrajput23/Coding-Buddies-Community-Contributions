#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX 

struct edge{
    int src;
    int des;
    int wt;
};

void bellman_ford(vector<edge> &edge_list, int E, int V){
    vector<int> parent(V, -1);
    vector<int> dis(V, inf);
    dis[0] = 0;
    for(int i = 0;i<V-1;i++){
        int f= 0;
        for(auto x: edge_list){
            int u = x.src;
            int v = x.des;
            int wt = x.wt;
            if(dis[u] + wt< dis[v]){
                f = 1;
                dis[v] = dis[u] + wt;
                parent[v] = u;
            }
        }
        if(f == 0){
            cout<<"No -ve edge wt cycle detected"<<endl;
            return;
        }
    }

    for(auto x: edge_list){
        int u = x.src;
        int v = x.des;
        int wt = x.wt;
        if(dis[u] + wt< dis[v]){
            cout<<"-ve edge wt cycle detected"<<endl;
            return;
        }
    }

    cout<<"No -ve edge wt cycle detected"<<endl;
}

int main(){
    int E, V;
    cin>>V>>E;
    vector<edge> edge_list;
    for(int i = 0;i<E;i++){
        edge t;
        int a, b, c;
        cin>>a>>b>>c;
        t.src = a;
        t.des = b;
        t.wt = c;
        edge_list.push_back(t);
    }

    bellman_ford(edge_list, E, V);
    return 0;
}