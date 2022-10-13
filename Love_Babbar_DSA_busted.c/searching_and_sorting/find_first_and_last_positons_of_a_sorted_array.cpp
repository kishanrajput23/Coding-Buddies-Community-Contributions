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

// time complexity:O(N)
// space complexity:O(1)
// It's an easy question done by me not seen from anywhere. 
vector<int> f(vector<int> a,int n,int x){
    vector<int> res(2, -1);
    if(a.size() ==0) return res;
    int n = a.size();
    int l = 0;
    int h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(a[m]<=x)l = m+1;
        else h = m-1;
    }
    if(h>=0 and h<=n-1 and a[h]== x) res[1] = h;
    l = 0;
    h = n-1;
    while(l<=h){
        int m = (l+h)/2;
        if(a[m]>=x)h = m-1;
        else l = m+1;
    }
    if(l>=0 and l<=n-1 and a[l]== x) res[0] = l;
    return res;
}

int32_t main()
{
    vector<int> a = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int n = a.size();
    int x = 5;
    vector<int> res = f(a, n, x);
    cout<<res[0]<<" "<<res[1]<<endl;
    return 0;
}