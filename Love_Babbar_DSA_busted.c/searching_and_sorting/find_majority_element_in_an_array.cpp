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
// there are two parts of this question
//1. majority element 1 
// 2. majority element 2

// 1. majority element 1. 
// return an element if the frequency of an element is greater than n/2. 
// using moore's voting  algorithm. 
// time complexity:O(N)
// spac complexity:O(1)
int majority_element1(vector<int> a){
    int n = a.size();
    if(n == 1) return a[0];
    int x = a[0];
    int c = 1;
    for(int i = 1;i<n;i++){
        if(c>0){
            if(x == a[i])c++;
            else c--;
        }
        else if(c == 0){
            x = a[i];
            c = 1;
        }
    }
    // x is the candidate element which can be the answer but not necessarily.
    int count = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == x) count++;
    }
    return count>n/2?x:-1;
}

// 2. majority element 2. 
// return the element if frequency of an element is greater than n/3. 
// e.g. 1, 1, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4 
// in above example we see that there can be more than one element as majority in this question. 
// extended moore's voting algirthm. 
// dry run for better understanding do not see from anybody 
// time complexity:O(N)
// space complexity:O(1)
void majority_element2(vector<int> a){
    int n = a.size();
    int y = -1;
    int z = -1;
    int cy = 0;
    int cz = 0;
    for(int i = 0;i<n;i++){
        if(a[i] == y)cy++;
        else if(a[i] ==z)cz++;
        else if(cy == 0){
            y = a[i];
            cy = 1;
        }
        else if(cz == 0){
            z = a[i];
            cz = 1;
        }
        else{
            cy--;
            cz--;
        }
    }
    // y and z are the candiaate elements.
    int county = 0;
    int countz = 0; 
    for(int i = 0;i<n;i++){
        if(a[i] == y) county++;
        else if(a[i] == z) countz++;
    }
    if(county>n/3 and countz>n/3)cout<<y<<" "<<z<<endl;
    else if(county>n/3) cout<<y<<" "<<-1<<endl;
    else if(countz>n/3)cout<<-1<<" "<<z<<endl;
    else cout<<-1<<" "<<-1<<endl;
}
int32_t main()
{
    vector<int> a1 = {4, 5, 4, 4, 6, 4};
    int res1 = majority_element1(a1);
    cout<<res1<<endl;

    vector<int> a2 = {1, 1, 1, 1, 1, 2, 2, 4, 4, 4, 4, 4};
    majority_element2(a2);

    return 0;
}