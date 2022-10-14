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

// This was an easy but tricky question, 
// just observe that ki we are using only the prvious row in the 2D matrix made for solving lcs, I had reduced that , Not seen from anywhere written code and logic myself, 
// made two vectors of size m+1, if we need to fill odd row then I fill it in t2 with the help of t1 and if filling even row, then fill it in t1 with the help of t2. 
// dry run the code for better understanding. 
// time complexity:O(N*N)
// space complexity:O(2*N)
int solve(string s1, string s2, int n, int m){
    vector<int> t1(m+1, 0);
    vector<int> t2(m+1);
    t2[0] = 0;
    for(int i = 1;i<n+1;i++){
        for(int j = 1;j<m+1;j++){
            if(i%2 !=0){
                if(s1[i-1] == s2[j-1]){
                    t2[j] = t1[j-1]+1;
                }
                else{
                    t2[j] = max(t2[j-1], t1[j]);
                }
            }
            else{
                if(s1[i-1] == s2[j-1]){
                    t1[j] = t2[j-1]+1;
                }
                else{
                    t1[j] = max(t1[j-1], t2[j]);
                }
            }
        }
    }
    if(n%2 !=0) return t2[m];
    return t1[m];
}
int32_t main()
{
	fast_cin();
    string s1 = "axcb";
    string s2 = "adc";
    int res = solve(s1, s2, s1.size(), s2.size());
    cout<<res<<endl;
	return 0;
}