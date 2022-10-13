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

void inorderT(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
    return;
}

// approach 1:  written by me 
// time comoplexity: O(N)
// space complexity: O(1)
// struct Node *mirror(struct Node *root)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }

//     struct Node *ptr = root->left;
//     root->left = mirror(root->right);
//     root->right = mirror(ptr);
//     return root;
// }

// approach 2: written from geeks for geeks 
// time complexity: O(N)
// space complexity: O(1)
void mirror(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    mirror(root->left);
    mirror(root->right);

    swap(root->left, root->right);
}
int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(8);
    struct Node *p2 = createNode(12);
    struct Node *p3 = createNode(7);
    struct Node *p4 = createNode(6);1

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
    // cout << diameter(p) << endl;
    inorderT(p);
    cout << endl;
    // struct Node *ptr = mirror(p);
    mirror(p);
    // cout << ptr << endl;
    inorderT(p);

    // DiaPair* a = diameter1(p);
    // cout << a->dia << endl;
    return 0;
}