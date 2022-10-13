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

void inorderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}



// converting a binary tree to a binary search tree
// approach 
// we know that the inorder traversal of a binary search tree is sorted 
// so we will store the inorder traversal of the given binary tree in a vector.
// then we would sort it. 
// then again we will do the inorder traversal and simply replace the root->data with the v[i]
// time complexity: O(NLOg(N))
// space complexity: O(N)
void inorderT(Node *root, vector<int> &v)
{
    if (!root)
    {
        return;
    }

    inorderT(root->left, v);
    v.push_back(root->data);
    inorderT(root->right, v);
}

void inorderTh(Node *root, vector<int> &v)
{
    static int i = 0;
    if (!root)
    {
        return;
    }

    inorderTh(root->left, v);
    // cout << root->data << " ";
    root->data = v[i++];
    inorderTh(root->right, v);
}

void btTobst(Node *root)
{
    vector<int> v;
    inorderT(root, v);
    int n = v.size();
    sort(v.begin(), v.end());
    inorderTh(root, v);
}


int main()
{
    struct Node *p = createNode(10);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(4);
    struct Node *p3 = createNode(15);
    struct Node *p4 = createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    btTobst(p);
    inorderTraversal(p);
    return 0;
}
