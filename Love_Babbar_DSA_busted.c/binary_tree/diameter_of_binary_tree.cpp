#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

int height(struct Node *root)
{
    if (root == NULL)
    {
        return -1;
    }

    int lht = height(root->left);
    int rht = height(root->right);
    int tht = max(lht, rht) + 1;
    return tht;
}

// approach 1: to find the diameter of a binary tree
// time complexity: O(N^2)
// space complexity: O(1)
int diameter(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int nd = height(root->left) + height(root->right) + 2;
    int dia = max(max(ld, rd), nd);
    return dia;
}

// approach 2:
// time complexity: O(N)
// space complexity: 1
// in approach 1 the height function is being called again and again so we could reduce this recursion by calculating height simultaneously by making a class
class DiaPair
{
    public:
    int dia;
    int ht;
};

DiaPair* diameter1(struct Node *root)
{
    if (root == NULL)
    {
        DiaPair* mps = new DiaPair();
        mps->dia = 0;
        mps->ht = -1;
        return mps;
    }
    DiaPair* l = diameter1(root->left);
    DiaPair* r = diameter1(root->right);
    int tht = l->ht + r->ht + 2;
    DiaPair* mp = new DiaPair();
    mp->ht = max(l->ht, r->ht) + 1;
    mp->dia = max(max(l->dia, r->dia), tht);
    return mp;
}
int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(3);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // inorderT(p);
    // cout << endl;
    // struct Node *ptr = remove(p, 5);
    // inorderT(p);

    // vector<int> a = reverse_level_order_traversal(p);
    // for (auto i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << height(p) << endl;
    cout << diameter(p) << endl;
    // DiaPair* a = diameter1(p);
    // cout << a->dia << endl;
    return 0;
}