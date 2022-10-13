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
// appraoch 1: 
// using dp 
// time complexity:O(N)
// space complexity:O(N)
// int f(vector<int> a,int n, vector<int> &t){
//     if(n<=0) return 0;
//     if(t[n]!= -1) return t[n];
//     return t[n]= max(f(a, n-2, t)+a[n-1], f(a, n-1, t));
// }

// approach 2: 
// converting in the tabular. 
// time complexity:O(N)
// space complexity:O(N)
// int f(vector<int> a,int n){
//     vector<int> t(n+1);
//     t[0] = 0;
//     t[1] = a[0];
//     t[2] = max(a[0],a[1]);
//     for(int i = 3;i<=n;i++){
//         t[i] = max(t[i-2]+a[i-1], t[i-1]);
//     }
//     return t[n];
// }

// approach 3: most optimised
// we can see that in the approach 2 we had used only index i-2 and i-1 so we can maintain 2 variables despite of maintaining the complete array. 
// time complexity:O(N)
// space complexity:O(1)
int f(vector<int> a,int n){
    vector<int> t(n+1);
    if(n == 0) return 0;
    if(n == 1) return a[0];
    if(n == 2) return max(a[0],a[1]);
    int ans;
    int minus2 = a[0];
    int minus1 = max(a[0], a[1]);
    for(int i = 3;i<=n;i++){
        ans = max(minus2 +a[i-1], minus1);
        minus2 = minus1;
        minus1 = ans;
    }
    return ans;
}

int32_t main()
{
    vector<int> a = {200, 2, 3,400};
    int n = a.size();
    // vector<int> t(n+1, -1);
    int res =f(a, n);
    cout<<res<<endl;
    return 0;
}