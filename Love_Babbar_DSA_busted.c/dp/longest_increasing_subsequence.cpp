#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef  long long           ll;
typedef  long double         ld;
#define  int                 ll 
#define  mp                  make_pair
#define  pb                  push_back
#define  INF                 2e18
#define  fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-12;

int justGreater(vector<int> &v, int ele){
    int l =0;
    int h = v.size()-1;
    while(l<h){
        int m = (l+h)/2;
        if(ele<v[m]){
            h = m;
        }
        else{
            l = m+1;
        }
    }
    return l;
}
int solve(vector<int>&a, int n){
    vector<int> v;
    v.pb(a[0]);
    for(int i = 1;i<n;i++){
        if(v[v.size()-1]<a[i]){
            v.pb(a[i]);
        }
        else{
            int x = justGreater(v, a[i]);
            v[x] = a[i];
        }
    }
    // for(int i = 0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;
    return v.size();
}
int32_t main()
{
	fast_cin();
    vector<int> a = {5,8,3,7,9,1};

    int n = a.size();
    int res = solve(a, n);
    cout<<res<<endl;
	return 0;
}