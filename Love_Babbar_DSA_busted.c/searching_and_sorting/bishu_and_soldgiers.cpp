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
// this was an easy question. 
// approach: sort the array only once and have the prefix sum stored . then apply binary search to find the number <=M . e.g.: arr[] = {1, 2, 2, 2, 2, 4}; // if duplicated exist then have the last one of <=M. here in this example for M = 2 index is 4. 
// time complexity:O(N*log(N))
// spacec complexity:O(N)
vector<int> prefixSumFunc(vector<int> a, int n){
    vector<int> v(n);
    v[0] = a[0];
    for(int i= 1;i<n;i++){
        v[i] = v[i-1] + a[i];
    }
    return v;
}
vector<int> f(vector<int> a,int n,int M, vector<int> prefixSum){
    int l= 0;
    int h = n-1;
    vector<int> res(2);
    while(l<=h){
        int m = l + (h-l)/2;
        // as duplicates can be there. 
        if(a[m]<=M) l = m+1;
        else h = m-1;
    }
    res[0] = h+1;
    res[1] = prefixSum[h];
    return res;
}

int32_t main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> prefixSum = prefixSumFunc(a, n);
    int q;
    cin>>q;
    while(q--){
        int M;
        cin>>M;
        vector<int> res = f(a, n, M, prefixSum);
        cout<<res[0]<<" "<<res[1]<<endl;
    }
    return 0;
}