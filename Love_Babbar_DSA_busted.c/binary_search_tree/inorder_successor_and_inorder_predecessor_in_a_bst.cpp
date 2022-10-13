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

// time complexity: O(N)
// space complexity: O(H)
void inorderSuccessor(Node *root, int val)
{
    static int prev = INT_MIN;
    if (root == NULL)
    {
        return;
    }

    inorderSuccessor(root->left, val);
    if (prev == val)
    {
        cout << root->data;
    }
    prev = root->data;
    inorderSuccessor(root->right, val);
}

//******************** 
// kindly redo this question see the approach from code library video
// time complexity can be O(H) optimise it. this will also help us to understand the morris traversal. 
// ************************

// time complexity: O(N)
// space complexity: O(H)
void inorderPredecessor(Node *root, int val)
{
    static int prev = INT_MAX;
    if (root == NULL)
    {
        return;
    }

    inorderPredecessor(root->left, val);
    if (root->data == val)
    {
        cout << prev;
    }
    prev = root->data;
    inorderPredecessor(root->right, val);
}
int main()
{
    struct Node *p = createNode(10);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // Node *temp = searchBST(p, 100);
    // cout << temp->data;

    inorderSuccessor(p, 5);
    cout<<" ";
    inorderPredecessor(p, 5);
    return 0;
}
