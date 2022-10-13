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

// this approach is of mcm type with i and j pointers 
// this gives tle 
// int solveUtil(int f,int e, vector<vector<int>> &t){
    
//     if(f == 0 or f == 1 or e == 1) return f;
//     if(t[f][e]!= -1) return t[f][e];
//     int res = INT_MAX;
//     for(int k = 1;k<=f;k++){
//         int temp = max(solveUtil(f-k, e, t), solveUtil(k-1, e-1, t));
//         res = min(temp, res);
//     }
//     return t[f][e] = res+1;
// }
int solveUtil(int f,int e, vector<vector<int>> &t){
    
    if(f == 0 or f == 1 or e == 1) return f;
    if(t[f][e]!= -1) return t[f][e];
    int res = INT_MAX;
    int l = 1;
    int h = f;
    while(l<=h){
        int m = (l+h)/2;
        int a1 = solveUtil(f-m, e, t);
        int a2 = solveUtil(m-1, e-1, t);
        if(a1<a2){
            h = m-1;
        }
        else l = m+1;
        int temp = max(a1, a2);
        res = min(temp,res);
    }
    return t[f][e] = res+1;
}
int solve(int f,int e){
    vector<vector<int>> t(f+1, vector<int>(e+1, -1));
    int res = solveUtil(f,e,t);
    return res;
}
int32_t main()
{
	fast_cin();
    int f;
    cin>>f;
    int e;
    cin>>e;
    int res = solve(f, e);
    cout<<res<<endl;
	return 0;
}