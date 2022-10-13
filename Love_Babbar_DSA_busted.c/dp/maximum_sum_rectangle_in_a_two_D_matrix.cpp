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
// this is the new concept 
// if the question is asked maximum rectangle 
// this is application of kadanes algorithm. 
// try to convert 2d matrix to 1d matrix. 
// then always try to convert the 2d matrix with this in a 1d array 
// see aditya rajiv video for it. 
// time complexity:O(N*N*N)
// space complexity:O(N*N)
int kadane(vector<int> arr,int &si,int &ei){
    int csum = arr[0];
    int msum = arr[0];
    si = 0;
    ei = 0;
    int tsi = 0;
    for(int i = 1;i<arr.size();i++){
        if(csum>=0){
            csum+= arr[i];
        }
        else{
            csum = arr[i];
            tsi = i;
        }
        if(csum>msum){
            msum = csum;  
            si = tsi;
            ei = i;
        } 
    }
    return msum;
}
int solve(vector<vector<int>> &v){
    int maxSum = INT_MIN;
    int finalTop, finalBottom, finalLeft, finalRight;
    int si;
    int ei;
    for(int k = 0;k<v[0].size();k++){
        vector<int> temp(v.size(), 0);
        for(int j = k;j<v[0].size();j++){
            for(int i = 0;i<v.size();i++){
                temp[i]+= v[i][j];
            }
            int sum = kadane(temp, si, ei);
            // maxSum = max(sum, maxSum);
            if(sum>maxSum){
                maxSum = sum;
                finalLeft = k;
                finalRight = j;
                finalTop = si;
                finalBottom = ei;
            }
        }
    }
    // cout<<finalTop<<" "<<finalBottom<<" "<<finalLeft<<" "<<finalRight<<endl;
    for(int i = finalTop;i<=finalBottom-finalTop+1;i++){
        for(int j = finalLeft;j<=finalRight-finalLeft+1;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return maxSum;
}

int32_t main()
{
	fast_cin();
    vector<vector<int>> v = {
        { 1, 2, -1, -4, -20 },
        { -8, -3, 4, 2, 1 },
        { 3, 8, 10, 1, 3 },
        { -4, -1, 1, 7, -6 }
    };
    int res = solve(v);
    cout<<res<<endl;
    return 0;
}