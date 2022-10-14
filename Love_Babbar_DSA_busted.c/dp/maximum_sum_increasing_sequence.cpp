#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef  long long           ll;
typedef  long double         ld;
#define  int                 ll 
#define  mp                  make_pair
#define  pb                  push_back
#define  INF                 2e18
#define  fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
ll MOD = 998244353;
double eps = 1e-12;
// this question is exactly similar to the approach 2 of lis told by pepcoding sir of lis, just have the maximum of previous elements of maximum sum lis, and add current element . 
// time complexity:O(n*n)
// space complexity:O(n)
int msiseq(int arr[], int n){
    vector<int> a;
    a.push_back(arr[0]);
    for(int i = 1;i<n;i++){
        int currmax = 0;
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]){
                currmax = max(currmax,a[j]);
            }
        }
        a.push_back(currmax+arr[i]);
    }
    int res = 0;
    for(int i = 0;i<n;i++){

        res = max(res, a[i]);
    }
    return res;
}
int32_t main()
{
	fast_cin();
    int arr[] = {1, 2, 3};
    int n = sizeof(arr)/sizeof(int);
    int res = msiseq(arr, n);
    cout<<res<<endl;
	return 0;
}