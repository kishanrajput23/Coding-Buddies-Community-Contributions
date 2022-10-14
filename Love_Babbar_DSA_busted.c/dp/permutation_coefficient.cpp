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
// This question says to find the nPr of n, and r, 
// This question can be done with many ways, doing with dp is not suggested. 
// as dp takes time complexity: O(n*r)
// do with simple method , 
// algo: 
// we know that, 
// nPr = n!/(n-r)!
// 

int nPr(int n,int r){
    int i = 0;
    int res = 1;
    while(i<r){
        res *= n-i;
        i++;
    }
    return res;
}
int32_t main()
{
	fast_cin();
    int n = 4;
    int r = 2;
    int res = nPr(n, r);
    cout<<res<<endl;
	return 0;
}
