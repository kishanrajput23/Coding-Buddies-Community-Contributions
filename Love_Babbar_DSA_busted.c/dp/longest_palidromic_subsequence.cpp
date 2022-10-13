#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int ll
#define pb push_back
#define INF 2e18
#define mp make_pair
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// already done this problem in notes. 
// time complexity:O(N*N)
// space complexity:O(N*N)
int lcs(string a, string b){
    int t[a.size()+1][b.size()+1];
    memset(t, -1, sizeof(t));
    for(int i = 0;i<a.size()+1;i++){
        for(int j = 0;j<b.size()+1;j++){
            if(i == 0 or j == 0) t[i][j] = 0;
            else if(a[i-1] == b[j-1]) t[i][j] = 1+ t[i-1][j-1];
            else t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[a.size()][b.size()];
}
int solve(string a){
    string b = a;
    reverse(b.begin(), b.end());
    int res = lcs(a, b);
    return res;
}
int32_t main()
{
    fast_cin();
    string a = "bbabcbcab";
    int res = solve(a);
    cout<<res<<endl;
    return 0;
}