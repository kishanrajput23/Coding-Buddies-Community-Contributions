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
// one would not be able to solve this problem, if not done before 
// to revise the logic see pepcoding video. 
// It uses kadane's algorithm: revise it from pepcoding sir. 
// we are asked to find the maximum difference of 0's and 1's in a substring. 
// we could convert it like number of more 0's then 1 , maximise it. 
// so we could write '0' as int -> 1
// and '1' as int -> -1 
// then find the maximum subarray sum , with kadane algorithm
// time complexity:O(N)
// space complexity:O(1)
int solve(int n,string s){
    int res = 0;
    int csum = 0;
    for(int i = 0;i<n;i++){
        int val;
        if(s[i]=='0'){
            val = 1;
        }
        else if(s[i] == '1'){
            val = -1;
        }

        if(csum>=0){
            csum += val;
        }
        else{
            csum = val;
        }

        if(res<csum ){
            res = csum;
        }
    }

    // if the string s contains all characters as 1. 
    if(res == 0) res = -1;
    return res;
}
int32_t main()
{
	fast_cin();
    string s = "1101";
    int res = solve(s.size(), s);
    cout<<res<<endl;
	return 0;
}