#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int          ll 
#define pb           push_back
#define INF          2e18
#define mp           make_pair
typedef long long    ll;
typedef long double  ld;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// already done , not written the code in copy see pepcoding video if forgot. 
// time complexity:O(N*N)
// space complexity:O(N*N)
int solveUtil(int a[],int n, int s, vector<vector<int>>&t){
    if(s == 0) return 1;
    if(n == 0) return 0;
    if(t[n][s]!= -1) return t[n][s];
    if(a[n-1]<=s){
        return t[n][s] = solveUtil(a, n-1, s, t)+solveUtil(a, n, s-a[n-1], t);
    }
    return t[n][s] = solveUtil(a, n-1, s, t);
}
int solve(int a[],int n,int s){
    vector<vector<int>> t(n+1, vector<int>(s+1, -1));

    int res = solveUtil(a, n, s, t);
    return res;
}
int32_t main()
{
	fast_cin();
    int a[] = {3, 5, 10};
    int n= 3;
    int s = 13;
    int res = solve(a, n, s);
    cout<<res<<endl;
	return 0;
}