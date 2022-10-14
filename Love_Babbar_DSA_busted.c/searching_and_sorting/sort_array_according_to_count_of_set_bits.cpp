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

// approach 1: 
// using inbuilt function to count set bits in number.
// __builtin_popcount helps us to calculate the number of set bits in a number, and stable_sort helps to sort an array in a stable manner. 
bool comp(const int &a,const int &b){
    return __builtin_popcount(a)>__builtin_popcount(b);
} 
void f(vector<int> a){
    stable_sort(a.begin(), a.end(), comp);
    for(auto x: a)cout<<x<<" ";
    cout<<endl;
}

// approach 2: 
// Interviewer will throw me out If I use the above approach 1. as using inbuilt functions is not allowed in an interview. 
// so I can do this with the help of kerningen's algo . This helps us to find the number of set bits in a number and that also efficiently. I will come back here later when I will study bit manipulation from pepcoding sir. 

int32_t main()
{
    vector<int> a ={5, 2, 3, 9, 4, 6, 7, 15, 32};
    f(a);
    return 0;
}