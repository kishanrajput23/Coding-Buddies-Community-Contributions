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
// not able to solve this problem but the problem was tricky but simple to understand
// the logic is if for any of the turns n-x, n-y, n-1 the A player is loosing , then this time for n, A player will definitely win as for n-x, n-y, n-1 the B player will loose
// read artice or see aditya rajiv video
// time complexity:O(N)
// space complexity:O(N)
int solve(int n,int x, int y){
    int t[n+1];
    t[0] = 0;
    t[1] = 1;
    for(int i = 2;i<n+1;i++){
        if(n-x>=0 and !t[n-x]){
            t[i] = 1;
        }
        else if(n-y>=0 and !t[n-y]){
            t[i] =1;
        }
        else if(n-1>=0 and !t[n-1]){
            t[i] = 1;
        }
        else{
            t[i] = 0;
        }
    }
    return t[n];
}
int32_t main()
{
    fast_cin();
    int n = 6;
    int x = 3;
    int y = 4;
    int res = solve(n, x, y);
    cout<<res<<endl;
    return 0;
}