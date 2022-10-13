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
// this question was medium level it corresponds to 2sum, 3sum and 4 sum problem. I did this problem myself. 
// dry run the code for better understanding. 
// time complexity:O(N*N)
// space complexity:O(1)
int f(vector<int> a,int sum){
    int n = a.size();
    sort(a.begin(), a.end());
    int res = 0;
    for(int i = 0;i<n-2;i++){
        int j = i+1;
        int k = n-1;
        int x = sum-a[i];
        while(j<k){
            if(a[j]+a[k]<x){
                res += k-j; 
                j++;
            }
            else k--;
        }
    }
    return res;
}
int32_t main()
{
    vector<int> a ={5, 1, 3, 4, 7};
    int sum = 12;
    int res = f(a, sum);
    cout<<res<<endl;

    return 0;
}