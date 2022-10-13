#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

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

struct Node *createNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// time complexity: O(N(logN))
// space complexity: O(n)
// this problem is similar to the problem as 
// minimum number of swaps to sort an array 
//see code library video for this. 
void convertLevelOrderToInorder(int *a, int n, vector<int> &v, int i)
{
    if (i >= n)
    {
        return;
    }

    convertLevelOrderToInorder(a, n, v, 2 * i + 1);
    v.push_back(a[i]);
    convertLevelOrderToInorder(a, n, v, 2 * i + 2);
}

int minSwaps(vector<int> &v)
{
    int c = 0;
    vector<pair<int, int>> arr;
    for (int i = 0; i < v.size(); i++)
    {
        arr.push_back({v[i], i});
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++)
    {
        if (i == arr[i].second)
        {
            continue;
        }
        else
        {
            c++;
            swap(arr[i], arr[arr[i].second]);
            i--;
        }
    }
    return c;
}
int main()
{
    int arr[] = {5, 6, 7, 8, 9, 10, 11};
    int n = sizeof(arr) / sizeof(int);
    vector<int> v;
    convertLevelOrderToInorder(arr, n, v, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << v[i] << " ";
    // }

    int mins = minSwaps(v);
    cout << mins;
    return 0;
}
