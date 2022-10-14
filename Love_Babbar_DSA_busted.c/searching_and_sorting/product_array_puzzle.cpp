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
// product array  puzzle 
// approach 1: 
// algo: multiply all the elements. and for each element divide with the given resultant multiplication. 
// take check of a specail case i.e. {0, 0, 2, 3} or {0, 2, 3}, {0, 0, 0}. basically we cannot divide a number by zero so if the zero frequency in the given array is 1, then all the elements in the array will be zero accept the element at position which contains zero and at that position we will simply put the product of the rest of the array. 
// another case when zero frequency is greater than or equal to 2 then answer will always be an array of size n containing the element value as zero. 
// In this approach we have traver the array two times. 
// time complexity:O(2*N)
// space complexity:O(N)
// vector<int> f(vector<int>& a, int n) {
//     int temp = 1;
//     int zero_freq = 0;
//     for(int i = 0;i<n;i++){
//         if(a[i]!= 0){
//             temp = temp* a[i];     
//         }
//         if(a[i] == 0)zero_freq++;
//     }
//     vector<int> res;
//     if(zero_freq == 1){
//         for(int i = 0;i<n;i++){
//             if(a[i]!= 0){
//                 res.push_back(0);
//             }
//             else{
//                 res.push_back(temp);
//             }
//         }
//     }
//     else if(zero_freq == 0){
//         for(int i = 0;i<n;i++){
//             res.push_back(temp/a[i]);
//         }           
//     }
//     else{
//         for(int i = 0;i<n;i++)res.push_back(0);
//     }

//     return res;       
// }

// approach 2: 
// seen from leetcode discuss , really a great approach. 
// maintain two variables that stores the product of left and that of right. 
// then by 2 pointer have the answer. 
// https://leetcode.com/problems/product-of-array-except-self/discuss/65627/O(n)-time-and-O(1)-space-C%2B%2B-solution-with-explanation
// time complexity:O(N)
// space complexity:O(1)
vector<int> f(vector<int> a,int n){
    int l = 1;
    int r = 1;
    int i= 0;
    int j = n-1;
    vector<int> res(n, 1);
    while(i<n and j>=0){
        res[i] *= l;
        l *= a[i];
        res[j] *= r;
        r *= a[j];
        i++;
        j--;
    }
    return res;
}
int32_t main()
{
    vector<int> a ={1, 0};
    int n = a.size();
    vector<int> res = f(a, n);
    for(int i = 0; i < n; i++)cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}