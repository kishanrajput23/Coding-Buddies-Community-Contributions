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
// approach 1: 
// this is dp based approach which is very easy. 
// just sort the elements as the first element will be the samllest and the last element will be the largest. 
// now solve it recursively if arr[j]-arr[i] >k so we answer can be either with be the f(i+1, j) or f(i, j-1) take minimum out of it. 
// time complexity:O(N*N)
// space complexity:O(N*N)
int t[1001][1001];
int solveUtil(int a[],int n,int k,int i,int j){
    if(i>=j) return 0;
    if(a[j]-a[i]<=k) return 0;
    if(t[i][j]!= -1) return t[i][j];
    return t[i][j] = 1+ min(solveUtil(a, n, k, i+1, j), solveUtil(a,n, k, i, j-1));
}
int solve(int a[],int n,int k){
    sort(a, a+n);
    int i = 0;
    int j = n-1;
    memset(t, -1,sizeof(t));
    int res = solveUtil(a, n, k, i, j);
    return res;
}


// approach 2
// not able to think of the optimise solution
// see aditya rajiv video for better understanding. 
// if we observe keenly we will see that we need to find arr[j]-arr[i]<=k with minimum removals, also --> arr[j]<=arr[i]+k and the array we had made is sorted . 
// so this is better sayable as it is the lower bound function. for each i find the maximum j, and take the minimum number of removals will be n-(j-i+1)
// time complexity:O(N*log(N))
// space complexity:O(1)
int binarySearch(int i,int a[],int n,int k){
    int l = i;
    int h = n-1;
    int temp = a[i]+k;
    while(l<=h){
        int m = (l+h)/2;
        if(a[m]<=temp){
            l = m+1;
        }
        else{
            h = m-1;
        }
    }
    return h;
}
int solve2(int a[],int n,int k){
    sort(a, a+n);
    int res = INT_MAX;
    for(int i = 0;i<n;i++){
        int j = binarySearch(i, a, n,  k);
        // if(i == j)continue;
        res = min(res, n-(j-i+1));
    }
    return res;
}

int32_t main()
{
	fast_cin();
    int n = 5;
    int a[] = {1, 5, 6, 2, 8};
    int k = 2;
    int res = solve(a, n, k);
    int res1 = solve2(a, n, k);
    cout<<res<<endl;
    cout<<res1<<endl;
	return 0;
}