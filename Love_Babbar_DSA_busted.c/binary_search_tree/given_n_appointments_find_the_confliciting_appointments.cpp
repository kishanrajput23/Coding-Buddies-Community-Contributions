#include <bits/stdc++.h>
using namespace std;

struct Node
{
public:
    int data;
    struct Node *left;
    struct Node *right;

    // Node(char val)
    // {
    //     data = val;
    //     left = NULL;
    //     right = NULL;
    // }
};

// brute force 
// approach 1:
// time complexity: O(N^N)
// space complexity: O(1)
// I have done this problem with brute force , but not able to understand efficient approach of bst
// I will come back to this question. 
void conflicitingAppointments(vector<pair<int, int>> &a)
{
    int n = a.size();
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j].second > a[i].first && a[i].first>a[j].first)
            {
                cout << "[" << a[i].first << ", " << a[i].second << "] is conflicted with "
                     << "[" << a[j].first << ", " << a[j].second << "]" << endl;
                break;
            }
        }
    }
}

int main()
{
    vector<pair<int, int>> a = {
        {1, 5},
        {3, 7},
        {2, 6},
        {10, 15},
        {5, 6},
        {4, 100}};
    conflicitingAppointments(a);
    return 0;
}
