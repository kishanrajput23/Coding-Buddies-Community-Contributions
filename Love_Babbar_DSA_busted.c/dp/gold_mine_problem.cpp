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
// this was a good question but easy to understand, I did it myself, 
// just check for the general case if i is valid then ,
// have faith that we will get answer if we go to right, right up, and right down, 
// then take the maximum out of them. 
// time complexity:O(N*M)
// space complexity:O(N*M)
// ***** there is also a gold mine problem 2 which is not given in love babbar sheet, so I am not doing it here , but I had understand the logic for it by pepcoding sir, print all possible paths with maximum gold, with dp , and bfs traversal of graph. ****
// that was also a good question. If want could see in revision. 
int isValid(int i, int j, int n,int m){
    if(i>=0 and i<n ) return 1;
    return 0;
}


int f(int n, int m, vector<vector<int>> &v, int i, int j,vector<vector<int>>& t){

    if(j>=m) return 0;
    int var1 = 0;
    int var2 = 0;
    int var3 = 0;
    if(t[i][j] != -1 ) return t[i][j];
    if(isValid(i, j+1, n, m)){
        var1 = v[i][j]+f(n, m, v, i, j+1, t);
    }
    if(isValid(i-1, j+1, n, m)){
        var2 = v[i][j]+ f(n, m, v, i-1, j+1, t);
    }
    if(isValid(i+1, j+1, n, m)){
        var3 = v[i][j]+ f(n, m, v, i+1, j+1, t);
    }
    return t[i][j] = max(var1, max(var2, var3));
}
int solve(int n, int m, vector<vector<int>> &v){
    int res = -1;
    vector<vector<int>> t(n+1, vector<int> (m+1, -1));
    for(int i = 0;i<n;i++){
        int temp = f(n, m, v, i, 0, t);
        // cout<<temp<<endl;
        if(res<temp) res = temp;

        // res = max(temp, res);
        // cout<<res<<endl;
    }
    return res;
}
int32_t main()
{
	fast_cin();
    int n = 3;
    int m = 3;
    vector<vector<int>> v = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0},
    };
    int res = solve(n,  m, v);
    cout<<res<<endl;
	return 0;
}