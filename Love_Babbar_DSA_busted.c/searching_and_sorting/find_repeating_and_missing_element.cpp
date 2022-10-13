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
double eps = 1e-6;

int* f(int*a ,int n){
    // code here
    int freq[n+1] = {0};
    int* res = new int[2];
    for(int i = 0;i<n;i++){
        freq[a[i]] = freq[a[i]] +1;
    }
    for(int i =1;i<n+1;i++){
        if(freq[i] == 2) res[0] = i;
        else if(freq[i] == 0) res[1] = i;
    }
    return res;
}
int32_t main()
{
    int n = 2;
    int a[n] = {2,2};
    int* res = f(a, n);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}