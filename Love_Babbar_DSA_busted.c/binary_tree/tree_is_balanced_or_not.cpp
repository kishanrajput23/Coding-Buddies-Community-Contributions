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

// appraoch 1;
// algo
// take a flag set to 1 then simply calculate the height
// check an additional condition if the lt - rt is greater than 1 than do flg as 0
// this was the utility function.
// then call isBalanced function check code for better understanding
// see the code library video for better understanding
// time complexity: O(N)
// space complexity: O(h) h is the height of the tree . this is the stack recursion space used during the recursive calls.
int flag = 1;
int height(Node *root)
{
    if (!root)
        return 0;

    int lht = height(root->left);
    int rht = height(root->right);

    if (abs(lht - rht) > 1)
    {
        flag = 0;
    }

    return max(lht, rht) + 1;
}

bool isBalanced(Node *root)
{
    // flag = 1;
    int ht = height(root);
    if (flag == 1)
    {
        return true;
    }

    return false;
}

// approach 2 this is similar to the diameter question
class balpair
{
    public:
    int ht;
    bool isbal;
};

balpair* isBalancedOrNot(Node *root)
{
    if (!root)
    {
        balpair* temp = new balpair();
        temp->ht = 0;
        temp->isbal = true;
        return temp;
    }

    balpair* lh = isBalancedOrNot(root->left);
    balpair* rh = isBalancedOrNot(root->right);

    balpair* gp = new balpair();
    if (abs(lh->ht - rh->ht) <= 1 && lh->isbal && rh->isbal)
    {
        gp->isbal = true;
    }
    else
    {
        gp->isbal = false;
    }
    gp->ht = max(lh->ht, rh->ht) + 1;
    return gp;
}
int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(8);
    struct Node *p2 = createNode(12);
    struct Node *p3 = createNode(7);
    struct Node *p4 = createNode(6);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // cout << isBalanced(p);
    balpair* res = isBalancedOrNot(p);
    cout << res->isbal;
    return 0;
}