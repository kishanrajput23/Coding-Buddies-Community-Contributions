#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>

using namespace std;
typedef   long long ll;
#define int ll 
typedef   long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
// this is a medium level question to understand ,not in the notes, not able to do this question, seen from tech dose video first 10 minutes only to understand the recursion . 
// algo: 
// try with brute force of recursion 
// I had faith that this function f() will return me the minimum number of operations required to convert n and m length strings from a to b. 
// if the characters are same then return the same funciton having faith that it will return me the answer of the n-1 , m-1 elements in the string. 
// else go for all the 3 operations
// insert: assuming to insert that element have faith that n, m-1 will give the answer. 
// delete: assuming to delete that item , faith for the answer n-1, m will give the answer 
// replace: just replace that character , and have faith for the answer n-1, m-1 will give the answer. 
// as you had performed one opeation, so add 1 to the minimum of all the operations. 
//******done with memoization *(*******)
int t[100][100];

int f(string s1, string s2,int n,int m){
    if(n == 0) return m;
    if(m == 0) return n;
    if(t[n][m] != -1) return t[n][m];
    // cout<<s1[n-1]<<" "<<s2[m-1]<<endl;
    if(s1[n-1] == s2[m-1]) return f(s1, s2, n-1, m-1);

    int insertion = f(s1, s2, n, m-1);
    int deletion = f(s1, s2, n-1, m);
    int replace = f(s1, s2, n-1, m-1);
    // cout<<insertion<<" "<<deletion<<" "<<replace<<endl;
    return t[n][m] = 1+ min(insertion, min(deletion, replace));
    // return 1+ min(f(s1, s1, n, m-1), min(f(s1, s2, n-1, m), f(s1, s2, n-1, m-1)));
}
int32_t main()
{
	fast_cin();
    string s1 = "abxy";
    string s2 = "abxz";

    int n = s1.size();
    int m = s2.size();

    memset(t, -1, sizeof(t));

    int res = f(s1, s2, n, m);
    cout<<res<<endl;

	return 0;
}