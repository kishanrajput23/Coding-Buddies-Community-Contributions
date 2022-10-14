#include <bits/stdc++.h>
using namespace std;

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

void inorder1(Node *root, int &n)
{
    if (!root)
    {
        return;
    }
    inorder1(root->left, n);
    n++;
    inorder1(root->right, n);
}

void inorder2(Node *root, int k, int &res)
{
    static int count = 0;
    if (!root)
    {
        return;
    }
    inorder2(root->left, k, res);
    count++;
    if (count == k)
    {
        res = root->data;
        return;
    }
    inorder2(root->right, k, res);
}

int kth_largest_element(Node *root, int k)
{
    if (!root)
    {
        return 0;
    }
    int res = 0;
    int n = 0;
    inorder1(root, n);
    // cout<<count1<<" ";
    k = n + 1 - k;
    inorder2(root, k, res);
    return res;
}

int main()
{
    struct Node *p = createNode(10);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(6);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int k = 6;

    int res = kth_largest_element(p, k);
    if (!res)
    {
        cout << "Invalid K";
    }
    else
    {
        cout << res;
    }
    return 0;
}
