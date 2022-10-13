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
// disclamer: question link says that we need to find the min cost path sum
// but when we go to the link it has question as the max cost path sum
// this question is same as of gold mine problem
// time complexity:O(N*N)
// space complexity:O(N*N)
int solve(int n, vector<vector<int>> &a){
    vector<vector<int>> t(n, vector<int>(n));
    int res = 0;
    for(int i = n-1;i>=0;i--){
        for(int j = n-1;j>=0;j--){
            if(i == n-1){
                t[i][j] = a[i][j];
            }
            else if(j == 0){
                t[i][j] = a[i][j]+ max(t[i+1][j], t[i+1][j+1]);
            }
            else if(j == n-1){
                t[i][j] = a[i][j] + max(t[i+1][j], t[i+1][j-1]);
            }
            else{
                t[i][j] = a[i][j] + max(t[i+1][j], max(t[i+1][j+1], t[i+1][j-1]));
            }
            if(i == 0){
                res = max(res, t[i][j]);
            }
        }
    }
    return res;
}
int32_t main()
{
	fast_cin();
    int n = 2;
    vector<vector<int>> v = {
        {348, 391},
        {618, 193}
    };
    int res = solve(n, v);
    cout<<res<<endl;
	return 0;
}