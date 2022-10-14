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
// this was a hard question to understand 
// given a numeric keypad , find the possible numbers that can be formed 
// such that we can go only left, right, top , bottom. 
// seen logic from pepcoding video the first logic only not the second one. 
// then code it myself. 
// time complexity:O(N)
// space complexity:O(N)
int solve(vector<vector<char>> &v,int n){
    int indx = 1;
    vector<vector<int>> t(4, vector<int>(3, 1));
    vector<vector<int>> nt(4, vector<int>(3, 0));
    t[3][0] = 1e9;
    t[3][2] = 1e9;
    int dx[5] ={0, 0, 1, 0, -1};
    int dy[5] = {0, 1, 0, -1, 0};
     while(indx<n){
        for(int i=0;i<=3;i++){
            for(int j = 0;j<=2;j++){
                nt[i][j] = 0;
                for(int k = 0;k<=4;k++){
                    int ni = i+dx[k];
                    int nj = j+dy[k];
                    if(ni>=0 && ni<=3 && nj>=0 && nj<= 2 && v[ni][nj]!= '*' && v[ni][nj]!= '#'){
                        nt[i][j] += t[ni][nj];
                    }
                }
            }
        }
        for(int i = 0;i<=3;i++){
            for(int j = 0;j<=2;j++){
                t[i][j] = nt[i][j];
            }
        }
        indx++;
    }
    int sum = 0;
    for(int i = 0;i<=3;i++){
        for(int j = 0;j<=2;j++){
            if(v[i][j]!= '*' && v[i][j]!= '#'){
                // cout<<t[i][j]<<" ";
                sum+= t[i][j];
            }
        }
    }
    // cout<<endl;
    return sum;
}
int32_t main()
{
	fast_cin();
    vector<vector<char>> v = {
        {1,   2,  3},
        {4,   5,  6},
        {7,   8,  9},
        {'*', 0, '#'}
    };
    int n = 5;
    int res = solve(v, n);
    cout<<res<<endl;
	return 0;
}