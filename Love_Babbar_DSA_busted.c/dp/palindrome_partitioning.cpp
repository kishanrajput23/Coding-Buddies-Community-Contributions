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
// this question is easy .it is of mcm, 
// it is already done in copy. 
// time complexity:O(N*N)
// space complexity:O(N*N)
int isPalindrome(string str,int n,int i,int j){
    while(i<j){
        if(str[i]!=str[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int solveUtil(string str, int n,int i,int j, vector<vector<int>> &t){
    if(i>=j or isPalindrome(str, n, i,j)) return 0;
    if(t[i][j]!= -1) return t[i][j];
    int res = INT_MAX;
    for(int k= i;k<j;k++){
        int var1 = 0;
        int var2 = 0;
        if(t[i][k]!= -1) var1 = t[i][k];
        else{
            var1 = solveUtil(str,n,i,k,t);
            t[i][k] = var1;
        }
        if(t[k+1][j]!= -1) var2 = t[k+1][j];
        else{
            var2 = solveUtil(str, n, k+1,j,t);
            t[k+1][j] = var2;
        }
        int temp = var1+var2+1;
        res =min(temp,res);
    } 
    return t[i][j] = res;
}
int solve(string str, int n){
    int i = 0;
    int j = n-1;
    vector<vector<int>> t(n+1,vector<int> (n+1, -1));
    int res = solveUtil(str, n, i, j, t);
    return res;
}
int32_t main()
{
	fast_cin();
    string str = "aaabba";
    int n = str.size();
    cout<<"working"<<endl;
    int res = solve(str, n);
    cout<<res<<endl;
	return 0;
}