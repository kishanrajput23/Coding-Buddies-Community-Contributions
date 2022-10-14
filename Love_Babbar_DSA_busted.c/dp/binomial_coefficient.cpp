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
// This is an interesting question 
// nCr : This problem is reduced to knapsack problem, coin change , 
// time complexity:O(n*r);
/// space complexity:O(n*r)
int nCr(int n,int r, vector<vector<int>> &t){
    if(n<r) return 0;
    if(n == r) return 1;
    if(r == 1) return n;
    if(r == 0) return 1;
    if(t[n][r] != -1) return t[n][r];
    return t[n][r] = (nCr(n-1, r-1, t)%MOD +nCr(n-1, r, t)%MOD)%MOD ;
}
int32_t main()
{
	fast_cin();
    int n = 5;
    int r = 2;
    vector<vector<int>> t(n+1, vector<int> (r+1, -1));

    int res = nCr(n, r, t);
    cout<<res<<endl;
	return 0;
}
