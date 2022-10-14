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

// there are two approaches to solve this problem, 
// approach 1: by knapsack similarity. 
// this is was an easy question but tricky , very similar to knapsack 
// just maintain a previous element to check the difference whether it is one or not 
//if  one then we had two choices either to select it or not 
// else not to select it. 
// time complexity;O(N*N)
//space complexity:O(N*N)

int f(int a[],int  n,int i, int pele, vector<vector<int>> &t){
    if(i == n) return 0;
    if(t[i][pele]!= -1) return t[i][pele];
    if(abs(pele - a[i])== 1){
        return t[i][pele] = max(1+f(a, n, i+1,a[i], t), f(a, n, i+1, pele, t));
    }
    return t[i][pele] = f(a,n, i+1, pele, t);
}
int solve(int a[],int n){
    int res = 0;
    int currmax = -1;
    for(int i = 0;i<n;i++) currmax = max(currmax, a[i]);
    vector<vector<int>> t(n+1, vector<int>(currmax+1, -1));
    for(int i = 0;i<n;i++){
        int pele = a[i];
        int temp = f(a, n, i+1, pele, t);
        res = max(temp+1, res);
    }
    return res;
}

// approach 2:
// This is an application of LIS, method by pepcoding sir. 
// make a t vector and store till there what is the maximum subsequence such that no elements have adjacent difference 1 , make two nested loops and then calculate 
// draw graph for better understanding. 
// time complexity:o(N*N)
// space complexity:O(N)
int solve1(int arr[],int n){
    vector<int> t;
    for(int i = 0;i<n;i++){
        int temp = 1;
        for(int j = 0;j<i;j++){
            if(abs(arr[j]-arr[i])== 1){
                temp = max(temp, t[j]+1);
            }
        }
        t.pb(temp);
    }
    int res = -1;
    for(int i = 0;i<n;i++) res = max(res, t[i]);
    return res;
}
int32_t main()
{
	fast_cin();
    // int arr[] = {431 ,714, 161, 440, 760, 979, 525, 760, 992 ,603, 956, 939, 397, 513 ,691, 339 ,188, 709, 816, 549, 6 ,606 ,392, 702, 739, 814, 446, 281, 372, 155, 252, 96, 765, 894, 966, 439, 338 ,137, 293, 751 ,985, 837 ,106, 529, 857, 442, 52 ,224 ,561, 83, 251, 253, 765, 336 ,254, 133, 556 ,69, 594,382, 717 ,108 ,355 ,74 ,811 ,839 ,912 ,331 ,71 ,336, 570, 15 ,149 ,436, 678, 62 ,793};  
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);
    // sort(arr, arr+n);
    // for(int i = 0;i<n;i++)cout<<arr[i]<<" ";
    // cout<<endl;
    int res = solve(arr, n);
    int res1 = solve1(arr, n);
    cout<<res<<endl;
    cout<<res1<<endl;
	return 0;
}