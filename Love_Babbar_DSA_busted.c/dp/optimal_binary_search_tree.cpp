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
// approach 1: 
// have the MCM appraoch this is a simple question have root of each bst and find the answer. 
// I don't know why this code is giving TLE on gfg site. 
// time complexity:O(N*N*N)
// space complexity:O(N*N)
int solveUtil(int arr[],int freq[],int n,int i,int j,int lvl, vector<vector<vector<int>>> &t){
    if(i>j) return 0;
    if(i == j) return lvl*freq[i];
    int res = INT_MAX;
    if(t[i][j][lvl]!=-1) return t[i][j][lvl];
    for(int k = i;k<=j;k++){
        int var1, var2;
        if(k>=1 and t[i][k-1][lvl+1]!= -1) var1 = t[i][k-1][lvl+1];
        else{
            var1 =solveUtil(arr, freq, n, i,k-1,lvl+1, t);
            t[i][k-1][lvl+1] = var1;
        } 
        if(k<n and t[k+1][j][lvl+1]!= -1) var2 = t[k+1][j][lvl+1];
        else{
            var2 =solveUtil(arr, freq, n, k+1,j,lvl+1, t);
            t[k+1][j][lvl+1] = var2;
        } 
        int temp = var1+var2+lvl*freq[k];
        res = min(temp, res);
    }
    return t[i][j][lvl] = res;
}
int solve(int arr[],int freq[],int n){
    int i = 0;
    int j = n-1;
    int lvl = 1;
    vector<vector<vector<int>>> t(n+1, vector<vector<int>> (n+1, vector<int> (n+1, -1)));
    int res = solveUtil(arr, freq, n, i, j,lvl, t);
    return res;
}


// appraoch 2: this approach is better in the sense here we need to use only 2D vector. 
// giving correct answer on gfg portal . 
// despite of using the levels we could add them from i to j each time. 
// time complexity:O(N*N*N)
// spacec complexity:O(N*N)
int sumThem(int freq[],int i,int j){
    int sum = 0;
    for(int k = i;k<=j;k++){
        sum+= freq[k];

    }
    return sum;
}
int solveUtil1(int arr[],int freq[],int n,int i,int j,vector<vector<int>> &t){
    if(i>j) return 0;
    if(i == j) return freq[i];
    int res = INT_MAX;
    int sum = sumThem(freq, i, j);
    // if(t[i][j]!=-1) return t[i][j];
    for(int k = i;k<=j;k++){
        int var1 = 0;
        int var2 = 0;
        if(k>=1){
            if(t[i][k-1]!= -1) var1 = t[i][k-1];
            else{
                var1 =solveUtil1(arr, freq, n, i,k-1,t);
                t[i][k-1] = var1;
            } 
        }
        if(k<n){
            if( t[k+1][j]!= -1) var2 = t[k+1][j];
            else{
                var2 =solveUtil1(arr, freq, n, k+1,j,t);
                t[k+1][j] = var2;
            } 
        }
        int temp = var1+var2;
        res = min(temp, res);
    }
    return t[i][j] = res+sum;
}
int solve1(int arr[],int freq[],int n){
    int i = 0;
    int j = n-1;
    vector<vector<int>> t(n+1, vector<int> (n+1, -1));
    int res = solveUtil1(arr, freq, n, i, j, t);
    return res;
}
int32_t main()
{
	fast_cin();
    int arr[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = 3;
    int res = solve(arr, freq, n);
    int res1 = solve1(arr, freq, n);
    cout<<res<<endl;
    cout<<res1<<endl;
	return 0;
}