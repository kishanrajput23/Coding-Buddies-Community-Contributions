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
// this was a hard question. 
// approach 1 made by me gives tle on coding ninjas, 
// approch 2 seen from code library and code it myself, 
// do not go for approach 1 ,  go for approach 2, 
// approach 1: tells the knapsack similar idea select each element have faith for the ansewr and keep that track you could have only 2 elements consecutive at maximum
// time complexity;O(N*N*2)
//space complexity:O(N*N)
int t[101][10001][3];
int f(int a[],int  n,int i, int csum, int ca){
    // if(ca == 0) return csum;
    if(i == n) return csum;
    if(t[i][csum][ca]!= -1) return t[i][csum][ca];
    if(ca){
        return t[i][csum][ca] = max(f(a, n, i+1, csum+a[i], ca-1), f(a, n, i+1, csum, 2));
    }
    return t[i][csum][ca] = f(a, n, i+1, csum, 2);
}
int solve(int a[],int n){
    int res = 0;
    memset(t,-1,sizeof(t));
    int currmax = 0;
    for(int i = 0;i<n;i++){
        int ca = 1;
        int temp = f(a, n, i+1, a[i], ca);
        // cout<<temp<<endl;
        currmax = max(temp, currmax);
    }
    return currmax;
}

// approach 2: 
// this approach is better than the first approach, 
// algo:
// 1. consider all possible cases which can be there 
// so there can be three cases
// case 1: select the last two elements then you cannot select the third last element, so have faith for the answer from four last elements, 
// case 2: select the last element, and not the second last element, and then have faith for the answer from third last elements, 
// case 3: do not select the last element, and have faith to have answer from second last answer. 
// time complexity:O(N)
// sapce complexity:O(N)

int solve1(int arr[],int n, vector<int> &dp){
    if(n == 0) return 0;
    if(n == 1) return arr[0];
    if(n == 2) return arr[0]+arr[1];
    if(dp[n] != -1) return dp[n];
    return dp[n] =max(solve1(arr, n-3)+arr[n-2]+arr[n-1], max(solve1(arr, n-2)+arr[n-1], solve1(arr, n-1)));
}
int32_t main()
{
	fast_cin();
    int arr[] = {3000, 2000, 1000, 3, 10};
    int n = sizeof(arr)/sizeof(int);
    vector<int> dp(n+1, -1);
    int res = solve1(arr, n);
    cout<<res<<endl;
	return 0;
}