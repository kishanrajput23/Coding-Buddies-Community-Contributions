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

// already done this question in copy 
// see notes this is of mcm 
// time complexity:O(N*N*N)
// space complexity:O(N*N)
int f(string s,int n,int i,int j, int isTrue, vector<vector<vector<int>>> &t){
    if(i>j) return 0;
    if(i == j){
        if(isTrue){
            return s[i]== 'T';
        }
        else{
            return s[i]== 'F';
        }
    }
    if(t[i][j][isTrue]!= -1) return t[i][j][isTrue];
    int ans = 0;
    for(int k = i+1;k<j;k = k+2){
        int lt, lf, rt, rf;
        if(t[i][k-1][1]!= -1){
            lt = t[i][k-1][1];
        }
        else{
            lt = f(s, n, i, k-1, 1, t);
            t[i][k-1][1] = lt;
        }
        if(t[i][k-1][0]!= -1){
            lf = t[i][k-1][0];
        }
        else{
            lf = f(s, n, i, k-1, 0, t);
            t[i][k-1][0] = lf;
        }
        if(t[k+1][j][1]!= -1){
            rt = t[k+1][j][1];
        }
        else{
            rt = f(s, n, k+1, j, 1, t);
            t[k+1][j][1] = rt;
        }
        if(t[k+1][j][0]!= -1){
            rf = t[k+1][j][0];
        }
        else{
            rf = f(s, n, k+1, j, 0, t);
            t[k+1][j][0] = rf;
        }

        // int lt = f(s, n, i, k-1, 1, t);
        // int lf = f(s, n, i, k-1, 0, t);
        // int rt = f(s, n, k+1, j, 1, t);
        // int rf = f(s, n, k+1, j, 0, t);
        if(s[k]== '&'){
            if(isTrue){
                ans+= lt*rt;
            }
            else{
                ans += lt*rf+lf*rt+lf*rf;
            }
        }
        else if(s[k]== '|'){
            if(isTrue){
                ans += lt*rf+lf*rt+lt*rt;

            }
            else{
                ans+= lf*rf;
            }
        }
        else if(s[k] == '^'){
            if(isTrue){
                ans+= lt*rf+lf*rt;
            }
            else{
                ans+= lf*rf+lt*rt;
            }
        }
        // cout<<ans<<endl;
        // if(ans == 638)cout<<"yes"<<endl;
    }
    return t[i][j][isTrue] = ans;
}
int solve(string s,int n){
    int i = 0;
    int j = n-1;
    int isTrue = 1;
    vector<vector<vector<int>>> t(n+1, vector<vector<int>> (n+1, vector<int>(2, -1)));

    int res = f(s, n, i, j, isTrue, t);
    return res;
}


int32_t main()
{
	fast_cin();
    string s = "T|F^F&T|F^F^F^T|T&T^T|F^T^F&F^T|T^F";
    int n = s.size();
    int res = solve(s, n);
    cout<<res<<endl;
    return 0;
}