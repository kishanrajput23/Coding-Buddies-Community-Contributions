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
// approach 1 which is wrong is that to find the lcs of first two strings , then find the lcs of the third string obtained from the lcs of first two strings and the third string. XXXXXXXXX
// string s1 = "ffmznimkkas";
//     string s2 = "vwsrenzkycx";
//     string s3 = "fxtlsgy";
// refer this example for understanding why this approach fails. 

// correct approach 
// this is exactly similar to the lcs of two strings see code for better understanding. think with all cases to understand the recursion.
// time complexity:o(n*m*o)
// space complexity:O(n*m*o)
int t[100][100][100];
int solve(string s1, string s2, string s3, int n,int m, int o){
    if(n == 0 or m==0 or o == 0) return 0;
    if(t[n][m][o]!= -1) return t[n][m][o];
    if(s1[n-1] == s2[m-1] and s2[m-1] == s3[o-1]){
        return t[n][m][o] = 1+solve(s1, s2, s3, n-1, m-1, o-1);
    }
    return t[n][m][o] = max(solve(s1, s2, s3, n, m, o-1), max(solve(s1, s2, s3, n-1,m,o), solve(s1, s2, s3, n, m-1, o)));
}

int32_t main()
{
	fast_cin();
    string s1 = "ffmznimkkas";
    string s2 = "vwsrenzkycx";
    string s3 = "fxtlsgy";
    memset(t, -1, sizeof(t));
    int res = solve(s1, s2, s3, s1.size(), s2.size(), s3.size());
    cout<<res<<endl;
	return 0;
}