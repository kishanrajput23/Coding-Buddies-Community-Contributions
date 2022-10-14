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
// this question is a really hard question and new concept came across called as ternary search. 
// Ternary search: this search is same as binary search in this we divide the whole range into three parts and we use it generally in more complex mathematically oriented questions. We have 2 mid and then we decide which range we have to neglect.
// there is a very rare chance to have this question in interview but done  the implementation is easy.
// algo: 
// just remember the parabola distance. 
// see from gfg article very good explanation is given. 
// time complexity:O(log3(N))
// space compelxity:O(1)


double distance_from_given_point_to_all_other_points_in_v(double x, int a, int b, int c, vector<pair<int,int>> &v){
    double y = -(double)(a*x+c)/(double)(b);
    double res = 0;
    for(int i = 0;i<v.size();i++){
        double doxc = abs(x-v[i].first);
        double doyc = abs(y-v[i].second);
        res += sqrt(doxc*doxc + doyc*doyc);
    }
    return res;
}
// using ternary search. 
void f(int a, int b,int c, vector<pair<int,int>>& v){
    double l = -1e6;
    double h = 1e6;
    while((h-l)>eps){
        double m1 = l + (h-l)/3.0;
        double m2 = h - (h-l)/3.0;
        double dis1, dis2;
        dis1 = distance_from_given_point_to_all_other_points_in_v(m1, a, b, c, v);
        dis2 = distance_from_given_point_to_all_other_points_in_v(m2, a, b, c, v);
        if(dis1<dis2) h = m2;
        else l = m1;
    }
    double minimum_distance = distance_from_given_point_to_all_other_points_in_v((l+h)/2.0, a, b, c, v);
    cout<<fixed<< setprecision(10)<<minimum_distance<<endl;
}

int32_t main()
{
    int a = 1;
    int b = -1;
    int c = -3;
    vector<pair<int,int>> v = {
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    f(a, b, c, v);

    return 0;
}