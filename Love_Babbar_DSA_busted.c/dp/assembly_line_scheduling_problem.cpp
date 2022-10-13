#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
typedef   long long ll;
#define int ll 
typedef   long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// this was a medium level question, can be done with graph also but too jhanjaht, 
// problem statement seems quite complex but after reading two to three times, seems easier, 
// done this problem myself not seen from anywhere. 
// I had done this problem with memoization in dp, traversing all possible paths, and then finding the minimum answer, 
// for more understanding use your brain. 
// time complexity:O(N*2*2)
// space complexity:O(N*2)
int e1 = 10;
int e2 = 12;
int x1 = 18;
int x2 = 7;

int f(vector<vector<int>> &a, vector<vector<int>> &t, int i, int j, int n,vector<vector<int>>& dp){
    if(j == n-1){
        if(i == 0) return a[i][j]+ x1;
        return a[i][j] + x2;
    }
    if(dp[i][j] != -1) return dp[i][j];
    if(i == 0) return dp[i][j] = a[i][j]+ min(f(a, t, i, j+1, n, dp), t[i][j+1]+ f(a, t, i+1, j+1, n, dp));
    return dp[i][j] = a[i][j]+ min(f(a, t, i, j+1, n, dp), t[i][j+1]+ f(a, t, i-1, j+1, n, dp));
}
int solve(vector<vector<int>> &a , vector<vector<int>> &t, int n){
    vector<vector<int>> dp(2, vector<int> (n+1, -1));
    int j = 0;
    int var1 = e1 + f(a, t, 0, j, n, dp);
    int var2 = e2 + f(a, t, 1, j, n, dp);
    return min(var1, var2);
}

int32_t main()
{
	fast_cin();
    int n = 4;
    vector<vector<int>> a = {
        {4, 5, 3, 2},
        {2, 10, 1, 4},
    };
    vector<vector<int>> t = {
        {0, 7, 4, 5},
        {0, 9, 2, 8},
    };
    int res = solve(a, t, n);
    cout<<res<<endl;
	return 0;
}