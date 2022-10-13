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
// It is a hard question to think see pepcoding video for better understanding. 
/// approach 1: memoization 
// algo: 
// Do the best you can and prepare for the worst happening. 
// take maximum for the gold you have. 
// take minimum as player 2 will take the maximum gold. 
/*

(i+2,j)(i+1,j-1)(i+1,j-1) (i,j-2)
(i+1)\   /j         i \      /j-1
      \ /              \    /
   (i+1,j)            (i,j-1)
        i\            /j
          ---(i,j)---
*/
// time complexity:O(N*N)
// space complexity:O(N*N)
int solveUtil(int n,int i,int j, int arr[], vector<vector<int>> &t){
    if(i>j) return 0;
    if(t[i][j]!= -1) return t[i][j];
    int x = arr[i]+min(solveUtil(n, i+2, j, arr , t), solveUtil(n, i+1, j-1, arr , t));
    int y = arr[j]+min(solveUtil(n, i, j-2, arr , t), solveUtil(n, i+1, j-1, arr , t));
    return t[i][j] = max(x, y);
}
int solve(int n, int arr[]){
    int i = 0;
    int j = n-1;
    vector<vector<int>> t(n+1, vector<int> (n+1, -1));
    int res = solveUtil(n, i, j, arr, t);
    return res;
}

// appraoch 2: tabulation gap strategy
// time complexity:O(N*N)
// space complexity:O(N*N)
int solve1(int n,int arr[]){
    int t[n][n];
    for(int g = 0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                t[i][j] = arr[i];
            }
            else if(g == 1){
                t[i][j] = max(arr[i],arr[j]);
            }
            else{
                int x = arr[i]+min(t[i+2][j], t[i+1][j-2]);
                int y = arr[j]+min(t[i][j-2],t[i+1][j-2]);
                t[i][j] = max(x,y);
            }
        }
    }
    return t[0][n-1];
}
int32_t main()
{
	fast_cin();
    int n = 6;
    int arr[] = {40, 5, 1, 2, 3, 5};
    int res = solve(n, arr);
    int res1 = solve1(n, arr);
    cout<<res<<endl;
    cout<<res1<<endl;
	return 0;
}