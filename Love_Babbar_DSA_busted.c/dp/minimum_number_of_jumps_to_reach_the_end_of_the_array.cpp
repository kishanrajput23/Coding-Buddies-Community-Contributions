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
// this is a hard question and was also present in the array part of the dsa sheet
// not able to solve 
//there are two approaches to solve this problem, 
// approach 1: the dynamic proramming approach which is very easy 
// see pepcoding video if forgot 
// logic: 
// create a dp of size n , at dp[n-1] = 0  
// start traversing from n-2, get the nested loop for the a[i], find the minimum jumps of it. 
// time complexity:O(N*N)
// space complexity:O(N)
int solve(int n,int a[]){
    if(n == 0) return INT_MAX;
    int dp[n] = {INT_MAX};
    dp[n-1] = 0;
    for(int i = n-2;i>=0;i--){
        int s = a[i];
        int temp = INT_MAX;
        for(int j = i+1;j<=i+s&&j<n;j++){
            temp = min(dp[j], temp);
        }
        dp[i] = temp+1;
    }
    // for(int i = 0;i<n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    return dp[0];
}

// approach 2: 
// this is a greedy solution , always try to find the maximum reach from that given position and have a steps variable , which tells number of steps to reach to the maxrange if steps are 0, then increase the jumps variable , jumps is initialised with 1 as we need to at least one jump if size of the array is two. 
// time complexity:O(N)
// space complexity:O(N)
int solve2(int n,int a[]){
    if(n == 0) return 0;
    if(a[0] == 0) return -1;
    int jumps = 1;
    int steps = a[0];
    int maxReach = a[0];
    for (int i = 1; i < n; i++){
        if(i == n-1) return jumps;
        maxReach = max(maxReach, i+a[i]);
        steps--;
        if(steps == 0){
            jumps++;
            if(maxReach-i<=0){
                return -1;
            }
            steps = maxReach-i;
        }
    }
    return -1;
}
int32_t main()
{
	fast_cin();
    int n = 10;
    int a[n] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
    int res = solve(n, a);
    int res2 = solve(n, a);
    // int res = INT_MAX;
    cout<<res<<endl;
    cout<<res2<<endl;
	return 0;
}