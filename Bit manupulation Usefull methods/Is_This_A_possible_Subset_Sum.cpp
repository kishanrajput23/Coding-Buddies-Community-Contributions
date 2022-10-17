#include <bits/stdc++.h>
using namespace std;

// Given a number and an array, check if the number is a possible subset sum of the array
// e.g. arr = {1, 2, 9} and n = 3
// then the answer is yes, because 4 = 1 + 2
// if n = 10, then the answer is yes, because 10 = 1 + 9
// but if n = 7, then the answer is no because 7 is not a possible subset sum of the array

/**********START************/
// Using bitset to generate all possible subsequence sum
const int MAX = 1000000; // 10^7
bitset<MAX> bt;          // This method will only work iff sum(arr[i]) < 10^7
void initialize(vector<int> arr)
{
    bt[0] = 1;
    for (auto &x : arr)
        bt = bt | (bt << x);
}
int main()
{
    vector<int> arr = {1, 2, 9};
    initialize(arr);

    vector<int> query = {3, 10, 7};
    for (auto &x : query)
    {
        if (bt[x])
            cout << "Yes " << x << " is a possible subset sum of the array" << endl;
        else
            cout << "No " << x << " is not a possible subset sum of the array" << endl;
    }
    return 0;
}