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
// this question makes me learn something new 
// there are two approaches to solve this problem, 
// 1. greedy 2. dp 
// approach 1 : greedy 
// if we obsereve keenly this is a standard greedy problem, like we had done maximum meetings in one room. 
// standard greedy and can be solved easily. 
// time complexity:O(N*logN + N)
// space complexity:O(N)
int solveUtil(int n,vector<pair<int,int>> &v, int i, int p, pair<int,int> curr){
    if(i == n) return 0;
    if(p<curr.first){
        return max(1+solveUtil(n, v, i+1,curr.second, v[i+1]), solveUtil(n, v, i+1, p, v[i+1]));
    }
    return solveUtil(n, v, i+1, p, v[i+1]);
}

int solve(int n,vector<pair<int,int>> &v){
    int res = 1;
    for(int i = 0;i<v.size();i++){
        pair<int,int> prev = v[i];
        int temp = solveUtil(n, v, i, prev.second, v[i]);
        // cout<<temp+1<<endl;
        res = max(temp+1, res);
    }
    return res;
}


//approach 2: 
// this is a dp based approach, this is something new, 
// we can do all greedy problems like this with greedy 
// this is an application on LIS. 
// ******just sort the elements from first or second  positon of each element,that won't matter. ******** 
// then apply lis by pepcoding sir. 
int solve1(int n,vector<pair<int,int>> &v){
    sort(v.begin(),v.end());
    vector<int> t;
    t.pb(1);
    for(int i = 1;i<n;i++){
        int temp = 0;
        for(int j = 0;j<i;j++){
            if(v[j].second<v[i].first){
                temp = max(temp, t[j]);
            }
        }
        t.pb(temp+1);
    }
    int res = 1;
    for(int i = 0;i<n;i++) res = max(res, t[i]);
    return res;
}
int32_t main()
{
	fast_cin();
    int n = 5;
    vector<pair<int,int>> v= {
        {5, 10}, {1, 60},{15, 28}, {27, 40},{50, 90}
    };
    int res = solve(n, v);
    int res1 = solve1(n, v);
    cout<<res<<endl;
    cout<<res1<<endl;
	return 0;
}