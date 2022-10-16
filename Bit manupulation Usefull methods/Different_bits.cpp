#include <bits/stdc++.h>
using namespace std;
// Question : How many bits are different in two numbers?
// Example : 13 = 1101
//           15 = 1111
//           Ans = 1 (2nd bit is differnt)

// Beginer Approach
// Time Complexity : O(log n)
// Space Complexity : O(log n)
int fn1(int a, int b)
{
    // store the bits and compare
    vector<int> v1, v2;
    while (a)
    {
        v1.push_back(a % 2);
        a /= 2;
    }
    while (b)
    {
        v2.push_back(b % 2);
        b /= 2;
    }
    int ans = 0;
    for (int i = 0; i < v1.size(); i++)
    {
        if (v1[i] != v2[i])
            ans++;
    }
    return ans;
}

int fn2(int a, int b)
{
    int ans = 0;
    while (a || b)
    {
        if (a % 2 != b % 2)
            ans++;
        a /= 2;
        b /= 2;
    }
    return ans;
}

// Using builtin function
// Time Complexity : O(log n)
// Space Complexity : O(1)
int countDiffernce(int a, int b)
{
    // xor will give the bits which are different
    return __builtin_popcount(a ^ b);
}

int main()
{
    cout << fn1(13, 15) << endl;
    cout << fn2(13, 15) << endl;
    cout << countDiffernce(13, 15) << endl;

    return 0;
}