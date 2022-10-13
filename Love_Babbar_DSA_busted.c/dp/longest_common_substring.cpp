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
// already done , not written the code in copy see pepcoding video if forgot. 
// time complexity:O(N*N)
// space complexity:O(N*N)
int solve(string s1, string s2, int n,int m){
    vector<vector<int>> t(n+1, vector<int>(m+1, -1));
    int res = INT_MIN;
    for(int i = 0;i<n+1;i++){
        for(int j = 0;j<m+1;j++){
            if(i == 0 or j == 0){
                t[i][j] = 0;
            }
            else if(s1[i-1]== s2[j-1]){
                t[i][j] = 1+ t[i-1][j-1];
            }
            else{
                t[i][j] = 0;
            }

            if(res<t[i][j]){
                res = t[i][j];
            }
        }
    }
    return res;
}
int32_t main()
{
	fast_cin();
    string s1 = "abcdgh";
    string s2 = "acdghr";
    int n = s1.size();
    int m = s2.size();
    int res = solve(s1, s2, n, m);
    cout<<res<<endl;
	return 0;
}