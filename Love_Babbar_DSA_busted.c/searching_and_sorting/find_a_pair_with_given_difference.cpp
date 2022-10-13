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
// There can be many approaches to this problem . I am writing two most optimised approaches here.

// approach 1. 
// sort the given array and find for each element whether the x+a[i] exists in the rest array by applying binary search on it.
// time complexity: O(N*log(N))
// space complexity:O(1)
int bs(vector<int>a,int n,int x,int l,int h){
    while(l<=h){
        int m = l + (h-l)/2;
        if(a[m] == x) return 1;
        else if(a[m]<x) l = m+1;
        else h = m-1;
    }
    return 0;
}
int f(vector<int> a, int n,int x){
    sort(a.begin(), a.end());
    for(int i = 0; i < n;i++){
        int l = i;
        int h = n-1;
        if(bs(a, n, x+a[i], l, h)== 1) return 1;
    }
    return 0;
}

// approach 2:
// store the elements in an unorder multiset and check whether it is in the set after adding the a[i] + x 
// time complexity:O(N) avg. case  and worst case O(N*N)
// space complexity:O(1)
// int f(vector<int> a,int n,int x){
//     unordered_multiset<int> s;
//     for(auto x: a)s.insert(x);
//     for(auto x: a)
//         if(s.find(x+a[i])!= s.end())
//             return 1;
//     return 0;
// }
int32_t main()
{
    vector<int> a = {5, 20, 3, 2, 50, 80};
    int n = a.size();
    int x= 45;
    int res = f(a, n, x);
    cout<<res<<endl;
    return 0;
}