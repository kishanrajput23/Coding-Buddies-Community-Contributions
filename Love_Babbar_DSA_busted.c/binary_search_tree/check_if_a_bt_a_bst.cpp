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

// I have already done this question in data structure and algorithms folder by sandeep jain sir gfg
// approach 1:
// do an inorder traversal and check whether it is sorted or not.
// time complexity: O(N)
// space complexity: O(h)
// void checkBSTUtil(Node *root, int &f)
// {
//     if(root == NULL)
//     {
//         return ;
//     }
//     static int prev = INT_MIN;
//     checkBSTUtil(root->left, f);

//     if (prev >= root->data)
//     {
//         f = 1;
//         return;
//     }

//     prev = root->data;
//     checkBSTUtil(root->right, f);
// }

// bool checkBST(Node *root)
// {
//     if (root == NULL)
//     {
//         return true;
//     }
//     int f = 0;
//     checkBSTUtil(root, f);
//     if (f)
//     {
//         return false;
//     }
//     else
//     {
//         return true;
//     }
// }

// appraoch 2: 
// take min and max range to solve the question
bool checkBSTUtil(Node* root, int &max, int &min)
{
    if(root == NULL)
    {
        return true;
    }

    return (root->data<max && root->data> min && checkBSTUtil(root->left, root->data, min) && checkBSTUtil(root->right, max, root->data));
}

bool checkBST(Node* root)
{
    if(root == NULL)
    {
        return true;
    }

    int max = INT_MAX;
    int min= INT_MIN;
    bool temp = checkBSTUtil(root, max, min);
    if(temp)
    {
        return true;
    }
    return false;
}
int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(3);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    if (checkBST(p))
    {
        cout << 1;
    }
    else
    {
        cout << 0;
    }
    return 0;
}
