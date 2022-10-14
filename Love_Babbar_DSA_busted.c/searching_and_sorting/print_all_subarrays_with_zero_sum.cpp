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
// count of subarrays with zero sum. 
// see pepcoding sir video for better understanding. 
// algo: 
// 1. use a map and store prefix sum frequency in it. If the number is already present then add it to the result and icrease the frequency by one. 
// 2. make Initially m[0] = 1 . e.g.: arr[] = {3, -1, -2, 2} 

// time complexity:O(N)
// space complexity:O(N)
int f(vector<int> a){
    int n = a.size();
    unordered_map<int,int> m;
    int res = 0;
    int prev = 0;
    m[0] = 1;
    for(int i = 0;i<n;i++){
        m[prev+a[i]]++;
        prev = prev+a[i];
    }
    for(auto x: m){
        int f= x.first;
        int s = x.second;
        // cout<<f<<" "<<s<<endl;
        res += (s*(s-1))/2;
    }
    return res;
}
int32_t main()
{
    vector<int> a ={6, -9, 11, -10, -15 ,-14, 18, 20, -12 ,7 ,3, -7, -8 ,-9 ,20, -1, 0, -6, 4, 18, -13 ,-10 ,-9, -6 ,-10, -9, -11, 3 ,12, 20};
    int res = f(a);
    cout<<res<<endl;

    return 0;
}