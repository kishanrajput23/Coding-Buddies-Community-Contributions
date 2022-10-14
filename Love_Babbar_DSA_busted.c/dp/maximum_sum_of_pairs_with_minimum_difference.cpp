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
// I was very close to the solution but not able to solve yet an easy problem 
// seen logic from aditya rajiv video , 
// logic says that to maximise the sum of the pairs 
//you need to minimise the difference of the pairs, which are adjacent to each other. // we had sorted it because we could have adjacent elements with min. difference together. 
// we will start from the largest element because there is always a possibily to select the maximum sum number. 
// time complexity:O(N*log(N))
// space complexity:O(N)
int solve(int n,vector<int>&v,int k){
    sort(v.begin(),v.end());
    int res =0;
    int i = n-1;
    while(i>0){
        if(v[i]-v[i-1]<k){
            res += v[i]+v[i-1];
            i = i-2;
        }
        else i--;
    }
    return res;
}

int32_t main()
{
	fast_cin();
    vector<int> v = {2, 4, 11, 13, 28, 12, 21, 14};
    int n = v.size();
    int k = 2;
    int res = solve(n, v, k);
    cout<<res<<endl;
	return 0;
}