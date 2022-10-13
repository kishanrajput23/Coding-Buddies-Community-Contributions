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

// see striver sir video 
// basically there are two problems based on this
// problem 1: 2 sum problem 
// problem 2: 4 sum problem 
// problem 1: 2 sum problem has four approaches to do 
// problem 2: 4 sum problem is the extension of 2 sum problem 

// problem 1: 4 approaches 
// approach 1: have two nested loops and where ever the sum of the pointers elements is same then simply print it. 
// time complexity:O(N*N)
// space complexity:O(N*N)

//approach 2: sort the array and use 2 pointer approach on it. i = 0, j = n-1 , if sum of both the elements of the i and j is smaller than the targe sum then increase i else if decrease j else push that i and j in the result. 
// time complexity:O(N*log(N)+N)
// space complexity:O(1)

// approach 3: use unordered map if the element x-a[i] is not present in the unordered map then push a[i]->i into the map. if x-a[i] is present then push it into the result. 
// time complexity:O(N) avg. time 
// space complexity:O(N)

// approach 4: sort the array and then have an outer then do binary search in the range i+1 to n-1. 
// time complexity:O(N*log(N))
// space complexity:O(1)

// problem 2: 4 sum we can use all the above approaches just have two nested loops then the problem reduces to the problem 1. 
// approch 2: will be the most optimised approach for  problem2 and approach 3 will be the most optimised for the problem 1. 
void f(vector<int> a,int n,int k){
    // the i counter i.e. the first element.
    int i = 0;

    // sorting the array 
    sort(a.begin(), a.end());

    // creating the res vector it should not contain duplicates. 
    vector<vector<int>> res;
    while(i<=n-4){
        // j for the inner loop i.e. second elmeent 
        int j = i+1;
        while(j<=n-3){
            // applying the approach 2. 
            int s = j+1;
            int e = n-1;
            int x = k-a[i]-a[j];
            while(s<e){
                if(a[s]+a[e] == x){
                    vector<int> temp = {a[i], a[j], a[s], a[e]};
                    res.push_back(temp);

                    // skipping the duplicates. 
                    while(s<n and a[s]== a[s+1])s++;
                    while(e>j and a[e]== a[e-1])e--;
                    s++;
                    e--;
                }
                else if(a[s]+a[e] < x){
                    // skipping the duplicates. 
                    while(s<n and a[s]== a[s+1])s++;
                    s++;
                }
                else if(a[s]+a[e] > x){
                    // skipping the duplicates. 
                    while(e>j and a[e]== a[e-1])e--;
                    e--;
                }
            }
            // skipping the duplicates. 
            while(j<=n-3 and a[j]==a[j+1]) j++;
            j++;
        }
        // skipping the duplicates. 
        while(i<=n-4 and a[i]==a[i+1]) i++;
        i++;
    }
    for(int i = 0;i<res.size();i++){
        for(int j = 0;j<4;j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    vector<int> a = {1,0,-1,0,-2,2};
    int n = a.size();
    int x= 0;
    f(a, n, x);
    return 0;
}