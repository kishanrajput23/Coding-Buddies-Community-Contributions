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
// This problem is already done in Aditya verma sir playlist. 
// time complexity:O(n*w);
// space complexity:O(n*w)
int solve(int val[], int wt[], int n, int w, vector<vector<int>> &t){
    if(n == 0 or w == 0) return 0;
    if(t[n][w] != -1) return t[n][w];
    if(wt[n-1]<=w)
        return t[n][w] = max(val[n-1]+solve(val, wt, n-1, w-wt[n-1], t), solve(val, wt, n-1, w, t));
    return t[n][w] =  solve(val, wt, n-1, w, t);
}
int32_t main()
{
	fast_cin();
    int val[] = {1, 2, 3};
    int wt[] = {4, 5, 1};
    int w = 4;
    int n = sizeof(wt)/sizeof(int);
    vector<vector<int>> t(n+1, vector<int> (w+1, -1));
    int res = solve(val, wt, n, w, t);
    cout<<res<<endl;
	return 0;
}
