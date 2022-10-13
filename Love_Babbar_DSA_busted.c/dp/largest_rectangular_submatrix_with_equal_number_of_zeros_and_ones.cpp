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
// largest rectangular submatrix whose sum is zero . 
// this is similar to the largest rectangle in a matrix. 
// here we will use largest zero subarray sum which we have used for 1d array. 
// simply convert 2d to 1d by the summing technique 
// time complexity:O(N*N*N)
// space complexity:O(N*N)
int largestZeroSubarraySum(vector<int>&arr,int &tup, int &tdown){
    int tui = 0;
    int tdi = 0;
    int tl = 0;
    int cl = 0;
    int csum = 0;
    tup = 0;
    tdown = 0;
    unordered_map<int,int> um;
    um[0] = -1;
    for(int i = 0;i<arr.size();i++){
        csum += arr[i];
        auto it = um.find(csum);
        if(it!= um.end()){
            cl = i-it->second;
            tui = it->second+1;
            tdi = i;
        }
        else{
            um[csum] = i;
        }
        if(cl>tl){
            tl = cl;
            tup = tui;
            tdown = tdi;
        }
    }
    return tl;
}
int solve(vector<vector<int>> &a){
    vector<vector<int>> v(a.size(), vector<int>(a[0].size(), 0));
    for(int i = 0;i<a.size();i++){
        for(int j = 0;j<a[0].size();j++){
            if(a[i][j]== 1){
                v[i][j] = 1;
            }
            else{
                v[i][j] = -1;
            }
        }
    }
    int fup,fdown,fleft,fright;
    int tup = 0;
    int tdown =0;
    int tarea =0;
    for(int left = 0;left<v[0].size();left++){
        vector<int> temp(v.size(), 0);
        for(int right = left;right<v[0].size();right++){
            for(int i = 0;i<v.size();i++){
                temp[i] += v[i][right];
            }
            int length = largestZeroSubarraySum(temp, tup, tdown);
            int breadth = right-left+1;
            int carea = length*breadth;
            if(carea>tarea){
                tarea = carea;
                fup = tup;
                fdown = tdown;
                fleft = left;
                fright = right;
            }
        }
    }
    // cout<<"The total area is "<<tarea<<endl;
    // cout<<"(up, down)->"<<fup<<" "<<fdown<<endl;
    // cout<<"(left, right)->"<<fleft<<" "<<fright<<endl;
    for(int i = fup;i<=fdown;i++){
        for(int j = fleft;j<=fright;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return tarea;
}

int32_t main()
{
	fast_cin();
    vector<vector<int>> v = {
        {0, 0, 1, 1},
        {0, 1, 1, 0},
        {1, 1, 1, 0},
        {1, 0, 0, 1}   
    };
    int res = solve(v);
    cout<<res<<endl;
    return 0;
}