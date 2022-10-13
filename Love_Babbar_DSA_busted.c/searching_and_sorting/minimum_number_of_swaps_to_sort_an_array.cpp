#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-6;

// this is an algorithm not at all intutive . to sove the given problem take use of graph. 
// read gfg article and dry run the code for better understanding. 
int f(vector<int> a){
    int n = a.size();
    vector<pair<int,int>> v(n);
    for(int i= 0;i<n;i++){
        v[i].first = a[i];
        v[i].second = i;
    }
    sort(v.begin(),v.end());
    vector<int> vis(n, 0);
    int res = 0;
    for(int i= 0;i<n;i++){
        int j = i;
        int c = 0;
        while(!vis[j]){
            vis[j] =1;
            c++;
            j = v[j].second;
        }
        res += c>0? (c-1):0;
    }
    return res;
}

int32_t main()
{
    vector<int> a ={2, 8, 5, 4};
    int res = f(a);
    cout<<res<<endl;
    return 0;
}