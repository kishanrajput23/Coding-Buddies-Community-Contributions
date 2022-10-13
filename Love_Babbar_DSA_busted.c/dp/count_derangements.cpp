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
typedef long long ll;
#define int ll
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// this is a hard question 
// the hard thing about it is to find the recursive relation 
// see aditya rajiv video for better understanding. 
// time complexity:O(N)
// space complexity:O(1)
int  solve(int n){
    int t[n+1];
    t[0] = 0;
    t[1] = 0;
    t[2] = 1;
    for(int i = 3;i<n+1;i++){
        t[i] = (i-1)*(t[i-1]+t[i-2]);
    }
    return t[n];
}
int32_t main()
{
    fast_cin();
    int n = 4;
    int res = solve(n);
    cout<<res<<endl;
    return 0;
}