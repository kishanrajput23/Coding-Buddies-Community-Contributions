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

int t[100][100];

int solve(vector<int> &a, int i, int j){
    if(i>=j) return 0;
    if(t[i][j] != -1) return t[i][j];
    // int temp = 0;
    int res = INT_MAX;
    for(int k = i;k<j;k++){
        // cout<<"HI"<<endl;
        int temp  =  solve(a, i, k) + solve(a, k+1, j) + a[i-1]*a[k]*a[j];
        // cout<<k<<endl;
        if(res>temp) res = temp;
    }
    // cout<<res<<endl;
    return t[i][j] = res;
}
int32_t main()
{
	fast_cin();
    vector<int> a = {10, 30, 50, 60};
    int n = a.size();
    int i = 1;
    int j = n-1;
    // t.clear();
    memset(t, -1, sizeof(t));
    int ans = solve(a, i, j);
    cout<<ans<<endl;
	return 0;
}