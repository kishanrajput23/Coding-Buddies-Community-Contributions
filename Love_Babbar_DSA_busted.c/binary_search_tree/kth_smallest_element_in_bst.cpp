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

void inorder1(Node* root, int k, int &res)
{
    static int count = 0;
    if(!root)
    {
        return;
    }

    inorder1(root->left, k, res);
    count++;
    if(count == k)
    {
        res = root->data;
        return;
    }
    inorder1(root->right, k, res);
}
int kth_smallest(Node* root, int k)
{
    if(!root)
    {
        return 0;
    }
    int res;

    inorder1(root, k, res);
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

    int k = 1;

    int res = kth_smallest(p, k);
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
