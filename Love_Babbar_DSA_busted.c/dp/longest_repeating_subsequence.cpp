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

int solve(string s, int n){
    vector<vector<int>> t(n+1, vector<int> (n+1, 0));
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<n+1;j++){
            if(i!=j and s[i-1] == s[j-1]){
                t[i][j] = t[i-1][j-1]+1;
            }
            else{
                t[i][j] = max(t[i-1][j], t[i][j-1]);
            }
        }
    }
    return t[n][n];
}
int32_t main()
{
	fast_cin();
    string s = "axxxy";
    int n = s.size();
    int res = solve(s, n);
    cout<<res<<endl;
	return 0;
}