#include <bits/stdc++.h>
using namespace std;

int getBit(int n, int pos)
{
    return (n & (1 << pos) != 0);
}

int setBit(int n, int pos)
{
    return (n | (1 << pos));
}

int clearBit(int n, int pos)
{
    int mask = ~(1 << pos);
    return (n & (mask));
}

int updateBit(int n, int pos, int val)
{
    int mask = ~(1 << pos);
    n = (n & (mask));
    return (n | (val << pos));
}

int main()
{
    // get using bit manipulation
    // int n = 5;
    // int pos= 2;
    // cout<<getBit(n, pos);

    // set using bit manipulation
    //     int n = 5;
    //     int pos = 1;
    //     cout << setBit(n, pos);

    // clear using bit manipulation
    // int n = 5;
    // int pos = 2;
    // cout << clearBit(n, pos);

    // update using bit manipulation
    int n = 5;
    int pos = 2;
    int val= 1;
    cout<<updateBit(n, pos, val);
}