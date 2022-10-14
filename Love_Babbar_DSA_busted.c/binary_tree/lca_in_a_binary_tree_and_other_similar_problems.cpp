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

//lca in a binary tree
//approach 1:
// time complexity: O(N)
//space complexity: O(N)
//algo :
// take all possible paths from the root node and store the path when we will find n1 or n2
// void lcautil(Node *root, vector<Node *> &v, int n, int &f)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     if (f)
//     {
//         v.push_back(root);
//     }

//     lcautil(root->left, v, n, f);
//     lcautil(root->right, v, n, f);

//     if (n == root->data)
//     {
//         f = 0;
//     }
//     if (f)
//     {
//         v.pop_back();
//     }
// }

// int lca(Node *root, int n1, int n2)
// {
//     vector<Node *> path1, path2;
//     int f = 1;
//     lcautil(root, path1, n1, f);
//     int fl = 1;
//     lcautil(root, path2, n2, fl);

//     int i = 0;
//     int j = 0;
//     while (1)
//     {
//         if (i == path1.size() or j == path2.size())
//         {
//             return -1;
//         }
//         if (path1[i]->data != path2[j]->data)
//         {
//             break;
//         }
//         i++;
//         j++;
//     }
//     return path1[i - 1]->data;
// }

//approach 2:
// time complexity: O(N)
// space complexity: O(h) where h, is the height of the tree.
// see the code library video for better understanding
Node *lca(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 or root->data == n2)
    {
        return root;
    }

    Node *l = lca(root->left, n1, n2);
    Node *r = lca(root->right, n1, n2);

    if (l != NULL and r != NULL)
    {
        return root;
    }

    if (l != NULL)
    {
        return l;
    }
    else
    {
        return r;
    }
}


int main()
{
    struct Node *p = createNode(0);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(-40);
    struct Node *p3 = createNode(10);
    struct Node *p4 = createNode(30);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    vector<Node *> v;
    // rtl(p, v);
    // msrtl(p, v);
    // cout << res << endl;
    // skfrtl(p, v, 30);

    Node* temp= lca(p, 10, 30);
    cout<<temp->data<<endl;

    return 0;
}
