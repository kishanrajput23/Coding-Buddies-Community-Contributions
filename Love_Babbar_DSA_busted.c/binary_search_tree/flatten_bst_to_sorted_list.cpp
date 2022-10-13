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
// play with the pointers 
void inorder(Node* root, Node* &temp)
{
    static Node* p = NULL;
    static Node* q;
    if(!root)
    {
        return;
    }
    inorder(root->left, temp);
    q = root;
    if(p != NULL)
    {
        p->right = q;
        q->left = NULL;
    }
    else
    {
        temp = root;
    }
    p = q;
    inorder(root->right, temp);
}

Node* flatten(Node* root)
{
    Node* temp = NULL;
    inorder(root, temp);
    return temp;
}
int main()
{
    struct Node *p = createNode(8);
    struct Node *p1 = createNode(7);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(9);
    struct Node *p5 = createNode(20);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p4;
    p2->right = p5;

    Node* temp = flatten(p);
    for (auto i = 0; i < 6; i++)
    {
        cout<<temp->data<<" ";
        temp = temp->right;
    }
    
    return 0;
}
