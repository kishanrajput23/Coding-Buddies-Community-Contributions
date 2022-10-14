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
// searching a key in a BST
// for recursive based appraoch
// time complexity: O(h)
//space complexity: O(h)
// Node *searchBST(Node *root, int val)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     if (root->data == val)
//     {
//         return root;
//     }
//     else if (root->data > val)
//     {
//         return searchBST(root->left, val);
//     }
//     else
//     {
//         return searchBST(root->right, val);
//     }
// }

//searching : this is efficient as it do not require any extra space
// time complexity: O(logN)
//space complexity: O(1)
// Node *searchBST(Node *root, int val)
// {

//     while (root != NULL)
//     {
//         if (root->data == val)
//         {
//             return root;
//         }
//         else if (root->data > val)
//         {
//             root = root->left;
//         }
//         else
//         {
//             root = root->right;
//         }
//     }
//     return root;
// }

// inserting in a BST
// recursive based approach to insert
// time complexity: O(logn)
// space complexity: O(1)
// Node *insertBST(Node *root, int val)
// {
//     if (root == NULL)
//     {
//         Node *temp = createNode(val);
//         return temp;
//     }

//     if (root->data == val)
//     {
//         return root;
//     }
//     else if (root->data > val)
//     {
//         root->left = insertBST(root->left, val);
//     }
//     else
//     {
//         root->right = insertBST(root->right, val);
//     }
//     return root;
// }

// inserting in a bst : iteratively 
// time complexity: O(logn)
// space complexity: O(1)
Node* insertBST(Node* root, int val)
{
    Node* parent = NULL;
    Node* temp = createNode(val);
    while(root != NULL)
    {
        parent = root;
        if(root->data == val)
        {
            return root;
        }
        else if(root->data>val)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }

    if(parent == NULL)
    {
        return temp;
    }
    else if(parent->data>val)
    {
        parent->left = temp;
    }
    else 
    {
        parent->right = temp;
    }
    return root;
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
