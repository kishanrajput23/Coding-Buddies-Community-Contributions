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
// This problem I had already done in Aditya verma sir playlist . 
// time complexity:O(n*s);
// space complexity:O(n*s)
int solve(int a[],int n,int s, vector<vector<int>> &t){
    // if(n == 0 or s == 0) return 1;
    if(s == 0) return 1;
    if(n == 0) return 0;
    if(t[n][s] != -1) return t[n][s];
    if(a[n-1]<=s) return t[n][s] = solve(a, n, s-a[n-1], t)+ solve(a, n-1, s, t);
    return t[n][s] = solve(a, n-1, s, t);
}
int32_t main()
{
	fast_cin();
    int a[] = {1, 2, 3};
    int n = sizeof(a)/sizeof(int);
    int  s = 4;
    vector<vector<int>> t(n+1, vector<int> (s+1, -1));
    int res = solve(a, n, s,  t);
    cout<<res<<endl;
	return 0;
}
