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
vector<int> f(vector<int> a,int n){
    vector<int> res;
    for(int i = 0;i<n;i++){
        if(a[i]==i+1) res.push_back(i+1);
    }
    return res;
}

int32_t main()
{
    vector<int> a = {15, 2, 45, 12, 7};
    int n = a.size();
    vector<int> res = f(a, n);
    for(int i = 0;i<res.size();i++)cout<<res[i]<<" ";
    cout<<endl;
    return 0;
}