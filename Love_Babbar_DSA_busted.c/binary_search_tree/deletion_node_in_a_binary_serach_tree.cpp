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

void inorderT(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}


// we could have both recursive and iterative traversal in a binary search tree. 
// I will do here recursive search
// time complexity: O(N)
// space complexity: O(H)
int maximum_in_a_tree(Node* root)
{
    if(root->right == NULL)
    {
        return root->data;
    }
    return deleteIt(root->right);
}

Node* deleteIt(Node* root, int val)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data>val)
    {
        root->left= deleteIt(root->left, val);
    }
    else if(root->data<val)
    {
        root->right = deleteIt(root->right, val);
    }
    else
    {
        if(root->left != NULL and root->right != NULL)
        {
            int lmax = maximum_in_a_tree(root->left);
            root->data = lmax;
            root->left = remove(root->left, lmax);
        }
        else if(root->left != NULL)
        {
            return root->left;
        }
        else if(root->right != NULL)
        {
            return root->right;
        }
        else
        {
            return NULL;
        }
    }
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

    inorderT(p);
    cout << endl;
    insertBST(p, 16);
    cout << endl;
    inorderT(p);
    return 0;
}
