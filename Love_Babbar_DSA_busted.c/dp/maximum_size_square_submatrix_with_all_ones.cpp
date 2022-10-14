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
// I was not able to do this question 
// this was a difficult question and seen from pepcoding sir. 
// logic simply says make a dp of n*m, and each box represents if it is taken as the top left box , then what maximum square can be formed, containing all the 1's
// take the minimum of all three i, j+1 ,, i+1, j ,, i+1, j+1
// time complexity:O(N*M)
// space complexity:O(N*M)

int solve(vector<vector<int>> &v){
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> t(n, vector<int>(m, 0));
    int res = 0;

    // this is done because of these test cases. 
    //if v = {{0, 0}, {0, 0}} res = 0;
    // if v = {{0,1}, {1, 0}} res = 1;
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            if(v[i][j] ==1) 
                res = 1;

    for(int i = n-1;i>=0;i--){
        for(int j =m-1;j>=0;j--){
            if(i == n-1 or j == m-1){
                t[i][j] = v[i][j];
            }
            else if(v[i][j]!=0){
                t[i][j] =1+ min(t[i][j+1],min(t[i+1][j], t[i+1][j+1]));
                if(res<t[i][j]) res = t[i][j];
            }            
        }
    }
    return res;
}

int32_t main()
{
	fast_cin();
    vector<vector<int>> v = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 1, 1},
        {1, 1, 1, 0}
    };
    int res = solve(v);
    cout<<res<<endl;
	return 0;
}