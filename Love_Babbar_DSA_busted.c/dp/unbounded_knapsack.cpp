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

int solve(int n,int w, int wt[],int val[]){
    int t[n+1][w+1];
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<w+1;j++){
            if(i == 0 or j == 0){
                t[i][j] = 0;
            }
            else if(wt[i-1]<=j){
                t[i][j] = max(t[i-1][j],val[i-1]+ t[i][j-wt[i-1]]);
            }
            else{
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][w];
}
int32_t main()
{
	fast_cin();
    int val[] ={1, 4, 5, 7};
    int wt[] ={1, 3, 4, 5};
    int n = 4;
    int w = 8;
    int res = solve(n,w, wt, val);
    cout<<res<<endl;
	return 0;
}