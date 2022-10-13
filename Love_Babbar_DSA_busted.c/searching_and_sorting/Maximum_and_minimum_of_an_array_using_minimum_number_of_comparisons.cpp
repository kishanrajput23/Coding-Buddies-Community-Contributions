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
// this is a tricky question. 
// algo:
// subtract form each and store in x, y and z, then have observations and find if x*y is greater than zero then return b else if x*z<0 less than zero then return a ele return c. this questin is more of observation based. 
// time complexity:O(1)
// space complexity:O(1)
int f(int a, int b,int c){
    int x= a-b;
    int y = b-c;
    int z = a-c;
    if(x*y>0) return b;
    else if(x*z<0) return a;
    return c;
}

int32_t main()
{
    int a, b, c;
    cin>>a>>b>>c;
    int res = f(a, b, c);
    cout<<res<<endl;
    return 0;
}