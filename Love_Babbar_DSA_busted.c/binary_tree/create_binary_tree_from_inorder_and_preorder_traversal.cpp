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

void inorderT(Node *root)
{
    if (!root)
    {
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

struct Node *createNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// time complexity: O(N)
//space complexity: O(N)
// we could either use int&indx or global int indx=0 or static int indx =0 in the recursive call. 
// create a map for inorder so that we could store them. 
// then traverse through the preorder and we know the property of inorder left, data, right, 
// so we will recursively call them until low == high
// see the code library video for better understanding. 
// int indx =0;
Node *createTreeUtil(int *in, int *pre, int low, int high, unordered_map<int, int> &m , int &indx)
{
    // static int indx =0;
    if (low > high)
    {
        return NULL;
    }

    Node *temp = createNode(pre[indx++]);
    if (low == high)
    {
        return temp;
    }

    int mid = m[temp->data];

    temp->left = createTreeUtil(in, pre, low, mid - 1, m, indx);
    temp->right = createTreeUtil(in, pre, mid + 1,high,  m, indx);
    return temp;
}

Node *buildTree(int *in, int *pre, int n)
{

    if (n == 0)
    {
        return NULL;
    }

    int indx = 0;
    int low = 0;
    int high = n-1;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[in[i]] = i;
    }

    Node *root = createTreeUtil(in, pre, low, high, m, indx);
    return root;
}
int main()
{
    // struct Node *p = createNode(1);
    // struct Node *p1 = createNode(2);
    // struct Node *p2 = createNode(3);
    // struct Node *p3 = createNode(4);
    // struct Node *p4 = createNode(5);

    // p->left = p1;
    // p->right = p2;
    // p1->left = p3;
    // p1->right = p4;

    // // sumTreeUtil(p);
    // sumTree(p);
    // inorderT(p);

    int in[] = {0, 2, 1, 3, 5};
    int pre[] = {3, 2, 0, 1, 5};
    Node *p = buildTree(in, pre, 5);
    inorderT(p);
    return 0;
}
