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

//time complexity: O(N)
// space complexity: O(N+N) = O(N) we are using two extra O(N) spaces here
// first is of the recursive calls and second is for the creating vector
// int maxSST(Node* root, vector<int> &v)
// {
//     // static int maxSum = INT_MIN;
//     if(!root)
//     {
//         return 0;
//     }

//     int lsum = maxSST(root->left, v);
//     int rsum = maxSST(root->right, v);
//     int currsum = lsum+ rsum+ root->data;
//     v.push_back(currsum);
//     // maxSum = max(maxSum, currsum);
//     return currsum;
// }

// int maxSSTUtil(Node* root)
// {
//     vector<int> v;
//     int ans = maxSST(root, v);
//     int maxSum = INT_MIN;
//     for (int i = 0; i < v.size(); i++)
//     {
//         maxSum = max(maxSum, v[i]);
//     }

//     return maxSum;
// }



int maxsum = INT_MIN;
//time complexity: O(N)
//space complexity: O(N)
int maxSST(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ls = maxSST(root->left);
    int rs = maxSST(root->right);
    int currsum = ls + rs + root->data;
    maxsum = max(maxsum, currsum);
    return currsum;
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
    int a = maxSST(p);
    cout << maxsum;
    return 0;
}
