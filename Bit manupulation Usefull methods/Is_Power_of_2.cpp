#include <bits/stdc++.h>
using namespace std;

// Using some STL functions
// Time Complexity: O(log n)
// Space complexity: O(1)
bool check1(int n)
{
    if (n == 0)
        return false;
    return (ceil(log2(n)) == floor(log2(n)));
}
// Without using STL functions
// Time Complexity: O(log n)
// Space complexity: O(1)
bool check2(int n)
{
    while (n > 1)
    {
        int rem = n % 2;
        if (rem)
            return false;
        n >>= 1;
    }
    return true;
}

// Efficient and shortest method
// Time complexity: O(1)
// Space complexity: O(1)
bool isPowerof2(int n)
{
    return !(n & (n - 1));
}
int main()
{

    // Here are differemt methods to check if a number is power of 2

    // 1. Using some STL functions
    check1(16) ? cout << "Yes\n" : cout << "No\n";
    check1(132) ? cout << "Yes\n" : cout << "No\n";

    // 2. Without using STL functions
    check2(16) ? cout << "Yes\n" : cout << "No\n";
    check2(132) ? cout << "Yes\n" : cout << "No\n";

    // 3. Efficient and shortest method
    isPowerof2(16) ? cout << "Yes\n" : cout << "No\n";
    isPowerof2(132) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}