#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll
#define ff first 
#define ss second 
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-6;
// this question was easy if description was clear. see code library video for better description. 
// time complexity:O(n*log(n))
// space complexity:O(N)
int solve(vector<pair<int,int>> v, int k){
    int res = -1;
    for(int i=0;i<v.size();i++){
        int csize = v[i].ss-v[i].ff+1;
        if(k>csize)k = k-csize;
        else{
            res = v[i].ff+ k-1;
            return res;
        }
    }
    return res;
}

int32_t main()
{
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<pair<int,int>> a(n);
        for(int i = 0;i<n;i++){
            int x, y;
            cin>>x>>y;
            a[i] = {x, y};
        }
        sort(a.begin(), a.end());
        vector<pair<int,int>> v;
        v.pb({a[0].ff, a[0].ss});
        int i= 0;
        int j = 1;
        while(j<n){
            if(v[i].ss>=a[j].ff) v[i].ss = max(v[i].ss, a[j].ss);
            else{
                v.pb({a[j].ff, a[j].ss});
                i++;
            }
            j++;
        }
        for(int i = 0;i<q;i++){
            int k;
            cin>>k;
            int res = solve(v, k);
            cout<<res<<endl;
        }
    }
    return 0;
}