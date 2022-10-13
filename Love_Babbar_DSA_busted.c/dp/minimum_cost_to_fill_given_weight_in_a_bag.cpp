#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int          ll 
#define pb           push_back
#define INF          2e18
#define mp           make_pair
typedef long long    ll;
typedef long double  ld;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// this question is easy , same as unbounded knapsack just keep check of the 0 based and 1 based indexing. 
int f(int a[],int n,int w, vector<vector<int>> &t){
    // cout<<csum<<endl;
    if(w == 0) return 0;
    if(n == 0) return 1e9;
    if(t[n][w] != -1) return t[n][w];
    if(n<=w and a[n-1] != -1){
        return t[n][w] =  min(a[n-1]+ f(a, n, w-n, t), f(a, n-1, w, t));
    }
    // cout<<"HI"<<endl;
    return t[n][w] = f(a, n-1, w,t);
}
int solve(int n,int a[], int w){
    // int csum = 0;
    vector<vector<int>> t(n+1, vector<int>(w+1, -1));
    int res = f(a, n, w, t);
    if(res >= 1e9) return -1;
    return res;
}

int32_t main()
{
	fast_cin();
    int n = 19;
    int a[] = {91, 43, 66, 91, 36 ,68 ,3 ,72,10 , 8, 36, 59, 89 ,67, 4, 42 ,34, 22 ,39};
    int w = 181;
    int res = solve(n, a, w);
    cout<<res<<endl;
	return 0;
}