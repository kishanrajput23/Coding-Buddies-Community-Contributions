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
// merging 2 sorted arrays without using extra space. see striver sir video for the better explanation. 
// time complexity:O((n+m)*(log(n+m)))
// space complexity:O(1)
// use gap method to do this. 
void f(vector<int> a1, vector<int> a2){
    int n = a1.size();
    int m = a2.size();
    int gap = ceil((n+m)/2.0);

    int indx = 0;
    while(gap>0){
        // cout<<gap<<endl;
        int i= 0;
        int j = i+gap;
        // cout<<indx<<endl;
        // indx++;
        if(i<n and j<n){
            while(i<n and j<n){
                // cout<<i<<" "<<j<<endl;
                // cout<<"first while"<<endl;
                if(a1[i]>a1[j])swap(a1[i],a1[j]);
                i++;
                j++;
                // cout<<i<<" "<<j<<endl;
            }
        }
        if(i<n and j>=n){
            while(i<n and j<n+m){
                // cout<<i<<" "<<j<<endl;
                // cout<<"second while"<<endl;
                if(a1[i]>a2[j-n]) swap(a1[i],a2[j-n]);
                i++,j++;
            }
        }
        if(i>=n and j>=n){
            while(j<n+m){
                // cout<<i<<" "<<j<<endl;
                // cout<<"third while"<<endl;
                if(a2[i-n]>a2[j-n])swap(a2[i-n],a2[j-n]);
                i++,j++;
            }
        }
        if(gap/2.0<1) break;
        gap = ceil(gap/2.0);
    }

    for(int i = 0;i<n;i++)cout<<a1[i]<<" ";
    for(int i = 0;i<m;i++)cout<<a2[i]<<" ";
    cout<<endl;
}
int32_t main()
{
    vector<int> a1 ={1, 5, 9, 10, 8, 20};
    vector<int> a2 = {2, 3, 8, 13};
    f(a1, a2);

    return 0;
}