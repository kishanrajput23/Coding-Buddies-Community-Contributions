#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef  unsigned long long  ll;
typedef  long double         ld;
#define  int                 ll 
#define  mp                  make_pair
#define  pb                  push_back
#define  INF                 2e18
#define  fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-12;

int countFriendsPairings(int n) 
{
    int t[n+1];
    // for(int i = 0;i<n+1;i++){
    //     t[n] = 0;
    // }
    t[0] = 1;
    t[1] = 1;
    for(int i =2;i<n+1;i++){
        t[i] = t[i-1]+(i-1)*t[i-2];
    }
    return t[n];
    // code here
}

int32_t main()
{
	fast_cin();
    int n = 6569;
    int res = countFriendsPairings(n);
    cout<<res<<endl;
	return 0;
}