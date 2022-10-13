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

// before doing this question of print all k sum paths in a binary tree I will do one more question
// question states that find the maximum sum from any node to any node there can be negative values in the binary tree.
// see tech dose video for better understanding and I had also written this in my DSA notebook
// int maxSumPath_util(Node *root, int &result)
// {
//     if (!root)
//     {
//         return 0;
//     }

//     int lsum = maxSumPath_util(root->left, result);
//     int rsum = maxSumPath_util(root->right, result);

//     int MS = max(max(lsum, rsum) + root->data, root->data);
//     int M21 = max(MS, lsum + root->data + rsum);
//     result = max(result, M21);

//     return MS;
// }

// int maxSumPath(Node *root)
// {
//     int result = INT_MIN;
//     maxSumPath_util(root, result);
//     return result;
// }

// time complexity: 3*N(for recursion) + h^2(for the two loops )== O(3*N+ H^2) = O(N)
//space complexity: O(N)
//the basic idea to solve a preorder traversal of the given tree. We also 
// We also need a container (vector) to keep track of the path that led to that node. At each node we check if there are any path that sums to k, if any we print the path and proceed recursively to print each path.
void printAllKSumPaths(Node *root, int k, vector<int> &v)
{
    if (!root) return;

    v.push_back(root->data);
    printAllKSumPaths(root->left, k, v);
    printAllKSumPaths(root->right, k, v);
    int f = 0;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        f += v[i];

        if (f == k)
        {
            for (int j = i; j < v.size(); j++)
            {
                cout << v[j] << " ";
            }
            cout << endl;
        }
    }
    v.pop_back();
}

int main()
{
    struct Node *p = createNode(0);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(-40);
    struct Node *p3 = createNode(10);
    struct Node *p4 = createNode(10);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // cout << maxSumPath(p);
    int k = 30;
    vector<int> v;
    printAllKSumPaths(p, k, v);
    return 0;
}
