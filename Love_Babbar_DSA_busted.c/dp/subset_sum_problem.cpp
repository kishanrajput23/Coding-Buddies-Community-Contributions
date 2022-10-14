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

int t[101][101];
bool solveUtil(int arr[], int n, int s){
    if(n == 0 and s == 0) return true;
    if(s == 0) return true;
    if(n == 0) return false;
    if(t[n][s] != -1) return t[n][s];
    if(arr[n-1]<= s){
        return t[n][s] = solveUtil(arr, n-1, s-arr[n-1]) or solveUtil(arr, n-1, s);
    }
    return t[n][s] = solveUtil(arr, n-1, s);
}

int sumArray(int arr[], int n){
    int sum = 0;
    for(int i = 0;i<n;i++){
        sum += arr[i];
    }
    return sum;
}
bool solve(int arr[], int n){
    int S = sumArray(arr, n);
    if(S%2 == 0)
        return solveUtil(arr,n, S/2);

    return false;

}
int32_t main()
{
	fast_cin();
    int arr[] = {1, 6, 11, 5};
    int n = sizeof(arr)/sizeof(int);
    memset(t, -1, sizeof(t));
    bool res = solve(arr, n);
    cout<<res<<endl;
	return 0;
}