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
struct t{
    int s;
    int e;
    int p;
};

// this is a very famous interview question. 
// we have done a question, called job scheduling with greedy or maximum meetings in a room, 
// here also we are given with st, et, profit is extra parameter, 
// hsere being greedy won't work, you need to check all the cases and then find the answer so use dp here. 
// there can be many approaches to this problem, 
// approach 1: 
// this is made by me, similar to knapsack not memoized can be , 
// time complexity:O(2^N) // not memoized 
// if memoized time complexity:O(N*N)
int solve(int prev, t arr[],int i,int n){
    if(i==n) return 0;
    // cout<<prev<<endl;
    if(prev<=arr[i].s){
        return max(arr[i].p + solve(arr[i].e, arr, i+1, n), solve(prev, arr,i+1, n));
    }
    return solve(prev, arr, i+1, n);
}


// approach 2: 
// try a different way of thinking. 
// for this problem only as the non conflicting always lies previously 
// include the current element, and call recursively for the latest non conflicting 
// exclude the current element and call recursively for the rest n-1. 
// used binary search here, to find the previous latest 
// this is a unique question in itself. 
// time complexity:O(N*log(N))
// space coomplexity:O(N)
int bs(t arr[],int i){
    int l = 0;
    int h = i-1;
    while(l<=h){
        int m = (l+h)/2;
        if(arr[m].e <= arr[i].s){
            l = m+1;
        }
        else h = m-1;
    }
    return h;
}
bool comp(t s1, t s2){
    return s1.e<s2.e;
}
int solve1(t arr[],int n){
    if(n == 1) return arr[0].p;
    sort(arr, arr+n, comp);
    int t[n];
    t[0] = arr[0].p;
    for(int i = 1;i<n;i++){
        int j = bs(arr,i);
        int incl = arr[i].p;
        cout<<j<<endl;
        if(j != -1)  incl += t[j];
        int excl = t[i-1];
        t[i] = max(incl, excl);
    }
    return t[n-1];
}
int32_t main()
{
    fast_cin();
    t arr[] = {
        {1, 3, 20},
        {2, 5, 20},
        {3, 10, 100},
        {4, 6, 70},
        {6, 9, 60}
    };
    int n = 5;
    int res = solve(-1, arr, 0, n);
    int res1 = solve1(arr, n);
    cout<<res<<endl;
    cout<<res1<<endl;
    return 0;
}