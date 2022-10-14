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

void inorderTraversal(Node *root)
{
    if (!root)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void nbsttobbstUtil(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    nbsttobbstUtil(root->left, v);
    v.push_back(root->data);
    nbsttobbstUtil(root->right, v);
}

Node *convert(vector<int> &v, int low, int high)
{
    if (low > high)
    {
        return NULL;
    }

    int mid = (low + high) / 2;
    Node *root = createNode(v[mid]);
    root->left = convert(v, low, mid - 1);
    root->right = convert(v, mid + 1, high);
    return root;
}
Node *nbsttobbst(Node *root)
{
    vector<int> v;
    nbsttobbstUtil(root, v);
    int low = 0;
    int high = v.size()-1;
    root = convert(v, low, high);
    return root;
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

    inorderTraversal(p);
    Node* root = nbsttobbst(p);
    cout << endl;
    inorderTraversal(root);
    return 0;
}
