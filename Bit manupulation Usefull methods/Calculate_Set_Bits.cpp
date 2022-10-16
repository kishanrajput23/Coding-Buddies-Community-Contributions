#include <bits/stdc++.h>
using namespace std;

// Without using STL
// Time Complexity: O(log n)
// Space Complexity: O(1)
int count1a(int n)
{
    int ans = 0;
    while (n)
    {
        if (n % 2 == 1)
            ans++;
        n /= 2;
    }
    return ans;
}
// Similar to above but bitwise is somewhat faster
int count1b(int n)
{
    int ans = 0;
    while (n)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

// Using STL (bitset)
int count2(int n)
{
    return bitset<32>(n).count(); // use 64 for long long
}

// Using gnu compiler's builtin function
int count3(int n)
{
    return __builtin_popcount(n); // use __builtin_popcountll(n) for long long
}
int main()
{
    cout<<count1a(155)<<endl;
    cout<<count1b(155)<<endl;
    cout<<count2(155)<<endl;
    cout<<count3(155)<<endl;

    return 0;
}