#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

struct edge {
    int src;
    int des;
    int wt;
};

// Bellman ford algorithm 
// single source shortest path algorithm 
// time complexity: O(V*E)
// space complexixty: O(V)
void printIt(vector<int> &parent, vector<int> &dis);
// assuming the source is always 0 
void bellman_ford(vector<edge> &edge_list, int V, int E){
    vector<int> dis(V, inf);
    dis[0] = 0;
    vector<int> parent(V, -1);
    for(int i = 0;i<V-1;i++){
        int f = 0;
        for(auto x: edge_list){
            int u = x.src;
            int v = x.des;
            int wt = x.wt;
            if(dis[u] + wt< dis[v]){
                f = 1;
                dis[v] = dis[u] + wt;
                parent[v] = u;
            }

            if(f == 0){
                printIt(parent, dis);
                return;
            }
        }
    }

    for(auto x: edge_list){
        int u = x.src;
        int v = x.des;
        int wt = x.wt;
        if(dis[u] + wt< dis[v]){
            cout<<"-ve edge weight cycle detected "<<endl;
            return;
        }
    }

    printIt(parent, dis);
}

void printIt(vector<int> &parent, vector<int> &dis){
    for(int i = 0;i<parent.size();i++){
        cout<<"src: "<<parent[i]<<", des: "<<i<<" dis: "<<dis[i]<<endl;
    }
}
int main()
{
    vector<edge> edge_list;
    int V, E;
    cin>>V>>E;
    for(int i = 0;i<E;i++){
        edge t;
        cin>>t.src>>t.des>>t.wt;
        edge_list.push_back(t);
    }

    bellman_ford(edge_list, V, E);
    return 0;
}