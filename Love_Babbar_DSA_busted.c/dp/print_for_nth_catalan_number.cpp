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
// catalan number is the new concept 
// c(n) = summation(c(i)*c((n-1)-i)) increase i value till i =0 to i<n
// the question of catalan is very easy , but the important point lies int it's application. 
// I had solved all the application of the catalan numbers in the notes so see there. 
// I had done about 10 questions in my copy of catalan application. 
// catalan number 
// number of bsts
// count of valleys and mountains
// count brackets
// circle and chords
// number of ways of triangulation
// min. score of triangulation
// dyK words
//** number of paths in a grid from bottom left to top right such that all paths are above the diagonal. ** 
// there are more questions given on gfg on it's application. 
// ******* All questions are reducible to valley and mountain problem , if observe keenly*****
// just remember the series , 1, 1, 2, 5, 14....... 

// program 1:
// time complexity:O(N)
// space complexity:O(1)
int solve(int n, int * t){
    for(int k= 2;k<n+1;k++){
        int i = 0;
        int j = k - 1;
        while(i<=k-1 and j>=0){
            t[k] += t[i]*t[j];
            i++;
            j--;
        }
    }
    return t[n];
}

// program 2
// time complexity:O(N)
// space complexity:O(1)
int solve1(int n, int*t){
    // cout<<"i"<<endl;
    for(int i = 2;i<n+1;i++){
        for(int j = 0;j<i;j++){
            t[i] += t[j]*t[(i-1)-j];
        }
    }
    return t[n];
}

// program 3
// recursive solution 
// time complexity:O(N)
// space complexity:O(1)
int solve2(int n){
    if(n == 0 or n == 1) return 1;
    int res = 0;
    for(int i = 0;i<n;i++){
        res += solve2(i)*solve2(n-1-i);
    }
    return res;
}
int32_t main()
{
	fast_cin();
    int n = 3;
    int t[n+1] = {0};
    t[0] = 1;
    t[1] = 1;
    // int res = solve(n, t);
    // int res1 = solve1(n, t);
    int res2 = solve2(n);
    // for(int i = 0;i<n+1;i++){
    //     cout<<t[i]<<" ";
    // }
    // cout<<endl;
    cout<<res2<<endl;
	return 0;
}