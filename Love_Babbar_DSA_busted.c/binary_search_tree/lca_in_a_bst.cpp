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

//Problem: 1--> print all paths from root to leaf node
void rtl(Node *root, vector<Node *> &v)
{
    if (root == NULL)
    {
        return;
    }

    v.push_back(root);

    rtl(root->left, v);
    rtl(root->right, v);

    if (v[v.size() - 1]->left == NULL and v[v.size() - 1]->right == NULL)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i]->data << " ";
        }
        cout << endl;
    }

    v.pop_back();
}

//Problem 2:  finding maximum sum from root node to the leaf node
int res = INT_MIN;
void msrtl(Node *root, vector<Node *> &v)
{
    if (root == NULL)
    {
        return;
    }

    v.push_back(root);

    msrtl(root->left, v);
    msrtl(root->right, v);

    if (v[v.size() - 1]->left == NULL and v[v.size() - 1]->right == NULL)
    {
        int f = 0;
        for (int i = 0; i < v.size(); i++)
        {
            f += v[i]->data;
        }
        if (f > res)
        {
            res = f;
        }
    }
    v.pop_back();
}

//Problem 3:  print all the paths for which the sum is equal to k from root to leaf node
void skfrtl(Node *root, vector<Node *> &v, int k)
{
    if (root == NULL)
    {
        return;
    }

    v.push_back(root);

    skfrtl(root->left, v, k);
    skfrtl(root->right, v, k);

    if (v[v.size() - 1]->left == NULL and v[v.size() - 1]->right == NULL)
    {
        int f = 0;
        for (int i = 0; i < v.size(); i++)
        {
            f += v[i]->data;
        }
        if (f == k)
        {
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i]->data << " ";
            }
            cout << endl;
        }
    }

    v.pop_back();
}

// This question is different from lca in a binary tree. 
// algo: 
// if the current root is smaller thann both n1 and n2 then lca should be in the right subtree. 
// if the current root is greater than both n1 and n2 then lca should be in the left subtree. 
// else return the root . 
// time complexity: O(H)
// space complexity: O(1)
Node* lcaInBst(Node* root, int n1, int n2)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data < n1 && root->data <n2)
    {
        return lcaInBst(root->right, n1, n2);
    }
    else if(root->data >n1 && root->data>n2)
    {
        return lcaInBst(root->left, n1, n2);
    }
    else if(root->data >n1 && root->data<n2)
    {
        return root;
    }
    return root;
}


int main()
{
    struct Node *p = createNode(100);
    struct Node *p1 = createNode(50);
    struct Node *p2 = createNode(150);
    struct Node *p3 = createNode(25);
    struct Node *p4 = createNode(75);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int n1 = 25;
    int n2 = 75;
    Node * lca = lcaInBst(p, n1, n2);
    cout<<lca->data;

    return 0;
}
