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

// time complexity: O(log(N))
// space complexity: O(log(N))
Node* minimumInBST(Node* root)
{
    if(root->left == NULL)
    {
        return root;
    }
    return minimumInBST(root->left);
}

// time complexity: O(log(N))
// space complexity: O(log(N))
Node* maximumInBST(Node* root)
{
    if(root->right == NULL)
    {
        return root;
    }
    return maximumInBST(root->right);
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

    Node* temp = maximumInBST(p);
    Node* temp1 = minimumInBST(p);
    cout<<temp->data<<" "<<temp1->data;
    return 0;
}
