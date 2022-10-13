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
// this question is a very easy question very similar to 0-1 knapsack or count of subset sum. 
// time complexity:O(n*n)
// space complexity:O(n)

int solve(int arr[], int n, int cp,int k, vector<vector<int>> &t){
    if(n == 0) return 1;
    if(t[n][cp]!= -1) return t[n][cp];
    if(cp*arr[n-1]<=k){
        return t[n][cp] = solve(arr, n-1, cp*arr[n-1], k, t)+solve(arr, n-1, cp, k, t);
    }
    return t[n][cp] = solve(arr, n-1, cp, k, t);
}
int32_t main()
{
	fast_cin();
    int arr[] = {2, 4, 5, 3};
    int  n = sizeof(arr)/sizeof(int);
    int cp = 1;
    int k = 12;
    vector<vector<int>> t(n+1, vector<int> (k+1, -1));
    // memset(t, -1, sizeof(t));
    int res = solve(arr, n, cp,k, t);
    cout<<res-1<<endl;
	return 0;
}