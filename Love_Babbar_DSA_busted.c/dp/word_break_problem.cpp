#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
#define int ll
#define pb push_back
#define INF 2e18
#define mp make_pair
typedef long long ll;
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// this problem is exactly similar to the palidrome partitioning 
// mcm , use mcm 
// time complexity:O(N*N)
// space complexity:O(N*N)
int f(string a, unordered_set<string>&s, int i,int j, vector<vector<int>>  &t){
    if(s.find(a.substr(i, j-i+1))!= s.end()){
        return 1;
    }
    if(i>=j) return 0;
    if(t[i][j]!= -1) return t[i][j];
    for(int k = i;k<j;k++){
        int temp = f(a, s, i, k, t) and f(a, s, k+1, j, t);
        if(temp == 1) return t[i][j] = 1;
    }
    return t[i][j] = 0;
}
int solve(string a, vector<string>&b){
    unordered_set<string> s;
    for(int i = 0;i<=b.size()-1;i++){
        s.insert(b[i]);
    }
    int n = a.size();
    vector<vector<int>> t(n+1, vector<int> (n+1, -1));
    int i = 0;
    int j = a.size()-1;
    int res = f(a, s, i, j, t);
    return res;
}
int32_t main()
{
    fast_cin();
    vector<string> b ={ "i","like","sam","sung","samsung","mobile","ice","cream","icecream","man","go","mango" };
    string a = "ilikesamsungcreamgoman";
    int res = solve(a, b);
    cout<<res<<endl;
    return 0;
}