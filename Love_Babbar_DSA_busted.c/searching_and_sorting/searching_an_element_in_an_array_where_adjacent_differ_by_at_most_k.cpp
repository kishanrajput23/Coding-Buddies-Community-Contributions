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
// this is an easy question and we need to do normal linear search in it and just for optimisation we can skip specific number of elements by jumping as we know that current element x can have at most k difference with it's neighbours so x, x +/- k.. so we can jump by abs(a[i]-x)/k. 
// see code library video or dry run the code for better understanding see e.g. {2, 4, 6, 2, 4, 6, 8}
// time complexity:O(N)
// space complexity:O(1)
int search_when_differ_is_at_most_k(vector<int> &a,int k,int x){
    int n = a.size();
    if(n == 0) return -1;
    int i = 0;
    while(i<n){
        if(a[i] == x) return i;
        i = i + (abs(a[i]-x)/k>0? abs(a[i]-x)/k: 1);
    }
    return -1;
}
int32_t main()
{
    vector<int> a = {2, 4, 6, 4, 2, 4, 6, 8, 10, 8};
    int k = 2;
    int x= 8;// return the first found index. 
    int res = search_when_differ_is_at_most_k(a, k, x);
    cout<<res<<endl;
    return 0;
}