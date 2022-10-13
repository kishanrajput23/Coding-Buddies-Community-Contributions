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
//This was an easy question, if observe keenly 
// we are always having 3 choices either partition in x, y , z but if n<0 then that length is not possible to consider so return INT_MIN;
// done with memoization. 
//time complexity:O(N)
// space complexity:O(N)
int solve(int n,int x, int y, int z, int t[]){
    if(n == 0) return 0;
    if(n<0) return INT_MIN;
    if(t[n] != -1) return t[n];
    return t[n] = max(1+solve(n-x, x, y,z, t), max(1+solve(n-y, x, y, z, t),1+ solve(n-z, x, y, z, t)));
}
int32_t main()
{
	fast_cin();
    int n = 4;
    int x = 2;
    int y = 1;
    int z = 1;
    int t[n+1];
    memset(t, -1, sizeof(t));
    int res = solve(n, x, y, z,t);
    cout<<res<<endl;
	return 0;
}