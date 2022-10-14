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
// this was a very easy question just try to make the all possible binary trees and try to derive the formula. 
// time complexity:O(H)
// space complexity:O(H)
int solve(int h){
    int dp[h+1];
    dp[0] = 1;
    dp[1] = 1;
    for(int i = 2;i<h+1;i++){
        dp[i] = dp[i-1]*(dp[i-1]+2*dp[i-2]);
    }
    return dp[h];
}
int32_t main()
{
	fast_cin();
    int h = 4;
    int res = solve(h);
    cout<<res<<endl;
	return 0;
}