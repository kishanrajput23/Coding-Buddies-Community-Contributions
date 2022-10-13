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

// this is a hard problem to understand, 
// see aditya rajiv video for understanding the problem , use approach of code library sir, written code by myself. 
// see copy notes of dp , for later understanding. 


// program 1;
// this approach is by code library sir, much better as space is O(1)
// code is written by me , not seen from anywhere. 
// see Aditya rajiv video for understanding the problem. 
// time complexity:O(N)
// space complexity:O(1)
// cs --> current same ways to paint the fence
// cd --> current different ways to paint the fence. 
// ps --> previous same ways to paint the fence. 
// pd --> previous diff. ways to paint the fence. 
int solve(int n, int k){
    if(n == 0) return 0;
    if(n == 1) return k;
    int cs, cd, ps, pd;

    // initialized for n = 2 , if n = 2 then it will not go through the loop and simply print cs + cd, initially I had put cs, ps same and pd, cd same. 
    cs = k;
    ps = k;
    cd = k*(k-1);
    pd = k*(k-1);
    for(int i = 3;i<=n;i++){

        // calculate cs and cd
        cd = (ps + pd)*(k-1);
        cs = pd;

        // update ps, pd
        ps = cs;
        pd = cd;
    }

    // total ways will be cs + cd;
    return (cs+cd);
}

// program 2;
// this approch is from aditya rajiv, but I prefer approach 1, 
// time complexity:O(N)
// space complexity:O(N)
int solve2(int n, int k){
    int t[n+1];
    t[0] = 0;
    t[1] = k;
    t[2] = k*k;
    for(int i = 3;i<n+1;i++){
        t[i] = (t[i-1]+t[i-2])*(k-1);
    }
    return t[n];
}
int32_t main()
{
	fast_cin();
    int n = 3;
    int k = 3;
    int res = solve(n, k);
    int res2 = solve2(n, k);
    cout<<res<<endl;
    cout<<res2<<endl;
	return 0;
}