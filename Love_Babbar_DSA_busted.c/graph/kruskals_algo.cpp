#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int, int> ipair;

// this is called as krushkals algorithm 
// time complexity: O(Elog(E) + Elog(V))
// space complexity: O(V)
struct edge{
    int src;
    int des;
    int wt;
};

struct node{
    int parent;
    int rank;
};

bool comparator(edge a, edge b){
    return a.wt<b.wt;
}
int find(vector<node> &dsuf, int u){
    if(dsuf[u].parent == -1){
        return u;
    }
    return dsuf[u].parent = find(dsuf, dsuf[u].parent);
}

void union_op(vector<node> &dsuf, int u, int v){
    if(dsuf[u].rank <dsuf[v].rank){
        dsuf[u].parent = v;
    }
    else if(dsuf[v].rank <dsuf[u].rank){
        dsuf[v].parent = u;
    }
    else {
        dsuf[u].parent = v;
        dsuf[v].rank += 1;
    }
}

void krushkal_algo(vector<node> &dsuf, vector<edge> &mst, vector<edge> &edge_list, int V){
    sort(edge_list.begin(), edge_list.end(), comparator);
    int i = 0;
    for(auto x: edge_list){
        int u = x.src;
        int v = x.des;
        // int wt = x.wt;
        if(i == V-1){
            break;
        }
        int from = find(dsuf, u);
        int to = find(dsuf, v);
        if(from == to){
            continue;
        }
        mst.push_back(x);
        // cout<<u<<" "<<v<<" "<<x.wt<<endl;
        union_op(dsuf, from, to);
        i++;
    }
}

void printmst(vector<edge> &mst, int V){
    for (int i = 0; i < V-1; i++)
    {
        cout<<"src:"<<mst[i].src<<" "<<"des:"<<mst[i].des<<" "<<"wt:"<<mst[i].wt<<endl;
    }
    // cout<<"hi";
    
}
int main()
{
    int V, E;
    cin>>V>>E;
    vector<node> dsuf(V);
    for(int i = 0;i<V;i++){
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    vector<edge> edge_list(E);
    for(int i = 0;i<E;i++){
        edge temp;
        int a, b, c;
        cin>>a>>b>>c;
        temp.src = a;
        temp.des = b;
        temp.wt = c;
        edge_list.push_back(temp);
    }

    vector<edge> mst;
    krushkal_algo(dsuf, mst, edge_list, V);
    // cout<<mst.size();
    printmst(mst, V);
    return 0;
}