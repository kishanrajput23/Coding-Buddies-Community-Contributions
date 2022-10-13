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
 // done in copy. 
// memized code 
// I don't know why memoized code is not working on gfg , but It's working on leetcode, tabulation solutions are more efficient than memoized one. 
int solve(string s1,string s2, int n, int m, vector<vector<int>>&t){
    if(n == 0 or m == 0) return 0;
    if(t[n][m] != -1) return t[n][m];
    int var1 , var2, var3;
    if(s1[n-1] == s2[m-1]){
        if(t[n-1][m-1]!= -1){
             var1 = t[n-1][m-1];
        }
        else{
            var1 = solve(s1, s2, n-1, m-1, t);
            t[n-1][m-1] = var1;
        }
        return 1+var1;
    }
    if(t[n-1][m]!= -1){
        var2 = t[n-1][m];
    }
    else{
        var2 = solve(s1, s2, n-1, m, t);
        t[n-1][m] = var2;
    }
    if(t[n][m-1]!= -1){
        var3 = t[n][m-1];
    }
    else{
        var3 = solve(s1, s2, n,m-1, t);
        t[n][m-1] = var3;
    }
    return max(var2, var3);
}

// tabulation approach. 
int solve1(string s1, string s2, int n,int m){
    vector<vector<int>> t(n+1, vector<int> (m+1, 0));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(s1[i-1] == s2[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[n][m];
}
int32_t main()
{
	fast_cin();
    string s1 = "abcde";
    string s2 = "ace";
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> t(n+1, vector<int>(m+1, -1));
    int res = solve(s1, s2, n, m, t);
    int res1 = solve1(s1, s2, n, m);
    cout<<res<<endl;
    cout<<res1<<endl;
	return 0;
}