#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-12;

// most optimised appraoch.
// use binary search to implement it. 
// time complexity:O(log(n/2))
// space complexity:O(1)
int f(int x){
    if(x == 1) return 1;
    int l = 1;
    int h = x/2;
    while(l<=h){
        int m = l + (l-h)/2;
        if(m*m<=x) l = m+1;
        else h = m-1;
    }
    return h;
}

int32_t main()
{
    int x = 5;
    int res = f(x);
    cout<<res<<endl;
    return 0;
}