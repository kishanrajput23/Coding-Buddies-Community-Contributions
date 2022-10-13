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
typedef long long ll;
#define int ll
typedef long double ld;
ll MOD = 998244353;
double eps = 1e-12;
#define mp make_pair
#define pb push_back
#define INF 2e18
#define fast_cin()                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
// this was an easy question. 
// try to find the peaks draw the line diagram, 
// take care of the edge cases, 
// e.g. 9, 9, 10
// time complexity:O(N)
// space complexity:O(1)
int solve(vector<int> &a, int n)
{
    if (n <= 2)
        return n;
    int f = 0;
    int count = 1;
    // cout<<count<<endl;
    int j = 1;
    while (j < n)
    {
        if (a[j - 1] < a[j])
        {
            f = 1;
            break;
        }
        else if (a[j - 1] > a[j])
        {
            f = 0;
            break;
        }
        else
        {
            j++;
        }
    }
    // cout << j << endl;
    // cout << f << endl;
    for (int i = j; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            if (f == 0)
            {
                // cout << "HI" << endl;
                // cout<<count<<endl;
                count++;
                f = 1;
            }
        }
        else if (a[i - 1] > a[i])
        {
            if (f == 1)
            {
                count++;
                f = 0;
            }
        }
    }
    return count + 1;
}
int32_t main()
{
    fast_cin();
    vector<int> a = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int n = a.size();
    int res = solve(a, n);
    cout << res << endl;
    return 0;
}