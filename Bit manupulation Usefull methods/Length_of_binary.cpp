#include <bits/stdc++.h>
using namespace std;

// Let's say N = 13
// What's the length of binary representation of 13?
// 13 = 1101
// So, length of binary representation of 13 is 4

// Without using STL
// time complexity: O(log n)
// space complexity: O(1)
int fn1(int n)
{
    int len = 0;
    while (n)
    {
        n >>= 1; // n/=2
        len++;
    }
    return len;
}

// Using STL
int fn2(int n)
{
    return log2(n) + 1;
}

// Using gnu compiler's builtin function
// Subtracted from 32 because 
// 1. it returns the number of leading zeros and 
// 2. "int" is 32 bits
int fn3(int n)
{
    return 32 - __builtin_clz(n); // use 64 - __builtin_clzll(n) for long long
}


int main()
{
    cout << fn1(16) << endl;
    cout << fn2(16) << endl;
    cout << fn3(16) << endl;
    return 0;
}
