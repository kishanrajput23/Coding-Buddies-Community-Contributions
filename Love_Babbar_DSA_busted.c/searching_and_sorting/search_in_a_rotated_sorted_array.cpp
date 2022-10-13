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
double eps = 1e-12;

// done this question in the copy of binary search by aditya verma  sir. 
// there can be many approaches to solvem this problem. but I had discussed here two approaches only. 
// there is also a question on leetcode called as rotated sorted array 2 , in that the question is entirely same but there can be duplicate elements in the array, so just add an additional condition if a[m] and a[l] and a[h] are equal then simply ignore that case by either doing l++ or h--.


// approach 1. 
// time complexity:O(2*log(N))
// algo:
// find the minimum element of the rotated sorted array and apply binary search on left part of it and the right part of it.
int bs(int l,int h, int t, vector<int>&a){
    if(h == -1){
        if(a[0]== t) return 0;
        else return -1;
    } 
    while(l<=h){
        int m = l + (h-l)/2;
        if(a[m]== t){
            return m;
        }
        else if(a[m]<t){
            l = m+1;
        }
        else h = m-1;
    }
    return -1;
}
int search(vector<int>& a, int t) {
    if(a.size() == 1){
        if(a[0] == t) return 0;
        else return -1;
    }
    int l = 0;
    int h = a.size()-1;
    while(l<h){
        int m = l + (h-l)/2;
        if(a[m]>a[h]) l = m+1;
        else h = m;
    }
    int x = h;
    int ans1 = bs(0, x-1, t, a);
    int ans2 = bs(x, a.size()-1, t, a);
    if(ans1 == -1 and ans2 == -1) return -1;
    else if(ans1 == -1 and ans2 != -1) return ans2;
    else if(ans2 == -1 and ans1 != -1) return ans1;
    else if(ans1 != -1 and ans2 != -1) return ans1;
    return -1;
}


// approach 2. 
// time complexity:O(log(N))
// space complexity:O(1)
int f(vector<int> &a, int n,int x){
    int l = 0;
    int h = a.size()-1;
    while(l<=h){
        int m = l + (h-l)/2;
        if(a[m] == x) return m;
        else if(a[l]<=a[m]){
            if(a[l]<=x and x<=a[m]) h = m-1;
            else l = m+1;
        }
        else{
            if(a[m]<=x and x<=a[h]) l =m +1;
            else h = m-1;
        }
    }
    return -1;
}

int32_t main()
{
    vector<int> a = {4, 5, 6, 7, 0, 1, 2};
    int n = a.size();
    int x = 2;
    int res = f(a, n, x);
    cout<<res<<endl;
    return 0;
}