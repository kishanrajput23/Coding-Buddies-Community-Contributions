#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int          ll 
#define pb           push_back
#define INF          2e18
#define mp           make_pair
typedef long long    ll;
typedef long double  ld;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// just exactly opposite to that of the smallest subarray sum 
// see largest sum subarray of pepcoding sir.  
// time complexity:O(H)
// space complexity:O(H)
int solve(int n,int a[]){
    int csum = a[0];
    int res = a[0];
    for(int i = 1;i<n;i++){
        if(csum<=0){
            csum+= a[i];
        }
        else{
            csum = a[i];
        }

        if(res>csum) res = csum;
    }
    return res;
}
int32_t main()
{
	fast_cin();
    int n = 3;
    int a[] = {3, -1, -2};
    int res = solve(n, a);
    cout<<res<<endl;
	return 0;
}