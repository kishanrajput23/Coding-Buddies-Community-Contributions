#include <bits/stdc++.h>
using namespace std;
// I have done three problems here before doing lca question before this approach helps to traverse through all the paths from the root to any node of the binary tree.

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

// appraoch 1:
// time complexity:O(N^N) this is the worst case time complexity when when the preorder is sorted. i.e. the tree is skewed. but the average case time complexity: O(NLog(N))
// space complexity: O(h)
// Node *insertThem(Node *&root, int val)
// {
//     if (root == NULL)
//     {
//         Node *ptr = createNode(val);
//         return ptr;
//     }

//     if (root->data > val)
//     {
//         root->left = insertThem(root->left, val);
//     }
//     else if (root->data < val)
//     {
//         root->right = insertThem(root->right, val);
//     }

//     return root;
// }

// Node *constructBSTFromPreorder(int pre[], int n)
// {
//     Node *root = NULL;
//     Node *p[n];
//     for (int i = 0; i < n; i++)
//     {
//         root = insertThem(root, pre[i]);
//     }
//     return root;
// }

void inorderT(Node *root)
{
    if (!root)
    {
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

// approach 2:
// see tech dose video for understanding 
// the idea is to use the range method , as done in check a bt a bst . 
// algo: 
// Have the range of each element and then insert according to the range while calling them recursively. 
// time complexity: O(N)
// space complexity: O(H)
void constructBSTUtil(Node * &root, int pre[], int &n, int &min, int &max, int &i)
{
    if (i == n)
    {
        return;
    }
    if (pre[i] > min && pre[i] < max)
    {
        if (pre[i] < root->data)
        {
            root->left = createNode(pre[i]);
            i = i + 1;
            constructBSTUtil(root->left, pre, n, min, root->data, i);
        }
    }
    if (i == n)
    {
        return;
    }
    if (pre[i] > min && pre[i] < max)
    {
        if (pre[i] > root->data)
        {
            root->right = createNode(pre[i]);
            i = i + 1;
            constructBSTUtil(root->right, pre, n, root->data, max, i);
        }
    }
}
Node *constructBST(int pre[])
{
    Node *root = createNode(pre[0]);
    int min = INT_MIN;
    int max = INT_MAX;
    int i=1;
    int n = sizeof(pre)/sizeof(int);
    constructBSTUtil(root, pre, n, min, max, i);
    return root;
}
int main()
{
    int pre[] = {10, 5, 1, 7, 40, 30, 42};
    // Node *p = constructBSTFromPreorder(pre, 7);

    Node *p = constructBST(pre);
    inorderT(p);

    return 0;
}
