#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

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

//time complexity: O(N)
// space complexity: O(H)
int f = 1;
int checkUtil(Node *root)
{
    if (!root)
    {
        return 0;
    }

    int ls = checkUtil(root->left);
    int rs = checkUtil(root->right);
    int ts = ls + rs;

    if (ts == 0)
    {
        return ls + rs + root->data;
    }

    if (ts != root->data)
    {
        f = 0;
    }

    return ls + rs + root->data;
}
bool check(Node *root)
{

    int height = checkUtil(root);

    if (f == 0)
    {
        return false;
    }

    return true;
}
int main()
{
    struct Node *p = createNode(0);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(-40);
    struct Node *p3 = createNode(10);
    struct Node *p4 = createNode(10);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    cout<<check(p);
    return 0;
}
