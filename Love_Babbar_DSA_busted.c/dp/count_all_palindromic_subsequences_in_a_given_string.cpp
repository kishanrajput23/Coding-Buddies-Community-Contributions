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

// approach 1: 
// this naive approach is written by me and it's correct. 
// try to find all possible strings. 
// time complexity:O(2^N*N)
// space complexity:O(exponential)
int isPalindrome(string x){
    if(x == "") return 0;
    int i = 0;
    int j = x.size()-1;
    while(i<j){
        if(x[i]!= x[j]) return 0;
        i++;
        j--;
    }
    return 1;
}
int solve(string a, int n, string x){
    if(n == 0) return 0;
    // cout<<x<<endl;
    int var1, var2;
    // cout<<x+a[n-1]<<" "<<x<<endl;
    if(isPalindrome(x+a[n-1])){
        // cout<<x+a[n-1]<<endl;
        var1 = 1+solve(a, n-1, x+a[n-1]);
        // cout<<"inside palindrome condn "<<x<<endl;
    }
    else{
        var1 = solve(a, n-1, x+a[n-1]);
    }
    var2 = solve(a, n-1, x);
    return var1+var2;
    // return solve(a, n-1, x+a[n-1])+ solve(a, n-1, x); 
}

// approach 2: 
// not able to solve with the optimised approach, 
// see pepcoding video for understanding , written code myself. 
// time complexity:O(N*N)
// space complexity:O(N*N)
int solve1Util(string s,int i,int j, vector<vector<int>> &t){
    if(i>j) return 0;
    if(i == j) return 1;
    if(t[i][j]!= -1) return t[i][j];
    if(s[i]== s[j]) return t[i][j] = solve1Util(s, i+1, j, t)+solve1Util(s, i, j-1, t) + 1;
    return t[i][j] = solve1Util(s, i+1, j, t)+ solve1Util(s, i, j-1, t)-solve1Util(s, i+1, j-1, t);
}

int solve1(string s){
    int n = s.size();
    vector<vector<int>> t(n+1,vector<int>(n+1, -1));
    // memset(t, -1, sizeof(t));
    int res = solve1Util(s, 0, s.size()-1, t);
    return res;
}

// this is the dp based approach for above recursion 
// time complexity:O(N*N)
// space complexity:O(N*N)
int solve2(string s){
    int n = s.size();
    int t[n][n];
    for(int g = 0;g<n;g++){
        for(int i = 0,j = g;j<n;i++,j++){
            if(g == 0) t[i][j] = 1;
            else if(g == 1) t[i][j] = s[i]==s[j] ? 3:2;
            else{
                if(s[i]==s[j]){
                    t[i][j] = 1+t[i+1][j]+t[i][j-1];
                }
                else t[i][j] = t[i+1][j]+t[i][j-1]-t[i+1][j-1];
            }
        }
    }
    return t[0][n-1];
}

int32_t main()
{
    fast_cin();
    string a = "ccbbgd";
    int n = a.size();
    string x = "";
    int res = solve(a, n, x);
    int res1 = solve1(a);
    int res2 = solve2(a);
    cout<<res<<endl;
    cout<<res1<<endl;
    cout<<res2<<endl;
    return 0;
}