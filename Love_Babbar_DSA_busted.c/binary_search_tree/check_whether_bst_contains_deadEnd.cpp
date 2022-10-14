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


void deadEnd(Node *root, int &max, int &min, int &f)
{
    if (!root)
    {
        return;
    }

    deadEnd(root->left, root->data, min, f);
    if (!f)
    {
        if (root->left == NULL and root->right == NULL)
        {
            if (min + 1 == root->data && max - 1 == root->data)
            {
                f = 1;
            }
            else if (root->data == 1 && max == 2)
            {
                f = 1;
            }
        }
    }
    deadEnd(root->right, max, root->data, f);
}

// approach :
// simply it's similar to the is bt a bst. 
// time complexity: O(N)
// space complexity: O(H)
bool isDeadEnd(Node *root)
{
    int f =0;
    int max = INT_MAX;
    int min = INT_MIN;
    deadEnd(root,max, min, f);
    if(f)
    {
        // cout<<"Yes";
        return true;
    }
    else
    {
        // cout<<"No";
        return false;
    }
    
}
int main()
{
    struct Node *p = createNode(8);
    struct Node *p1 = createNode(7);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(9);
    struct Node *p5 = createNode(20);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p2->left = p4;
    p2->right = p5;

    deadEnd(p, INT_MAX, INT_MIN);
    if(f)
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    return 0;
}
