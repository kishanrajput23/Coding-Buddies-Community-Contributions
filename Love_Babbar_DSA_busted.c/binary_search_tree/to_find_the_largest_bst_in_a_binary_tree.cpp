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


// We need to find the largest binary search tree in a binary tree. 
// This is the expert level question to solve means very hard question. 
// Only see pepcoding video for understanding it. 
// Before doing this question 
// class BSTPair{
//     public:
//     int max;
//     int min;
//     bool isBST;
// };

// BSTPair* checkBST(Node* root)
// {
//     if(root == NULL)
//     {
//         BSTPair* p = new BSTPair();
//         p->max = INT_MIN;
//         p->min = INT_MAX;
//         p->isBST = true;
//         return p;
//     }
//     BSTPair* lp =  checkBST(root->left);
//     BSTPair* rp =  checkBST(root->right);

//     BSTPair* mp = new BSTPair();
//     mp->isBST = (lp->max<= root->data && rp->min >= root->data && lp->isBST && rp->isBST);
//     mp->max = max(max(lp->max, rp->max), root->data);
//     mp->min = min(min(lp->min, rp->min), root->data);
//     return mp;
// }

// Now I will do the question largest bst in a bt
// time complexity: O(N)
// space complexity: O(H)
class BSTPair{
    public:
    int max;
    int min;
    bool isBST;
    Node* largestBSTroot;
    int largestBSTsize;
};

BSTPair* checkBST(Node* root)
{
    if(root == NULL)
    {
        BSTPair* p = new BSTPair();
        p->max = INT_MIN;
        p->min = INT_MAX;
        p->isBST = true;
        return p;
    }
    BSTPair* lp =  checkBST(root->left);
    BSTPair* rp =  checkBST(root->right);

    BSTPair* mp = new BSTPair();
    mp->isBST = (lp->max<= root->data && rp->min >= root->data && lp->isBST && rp->isBST);
    mp->max = max(max(lp->max, rp->max), root->data);
    mp->min = min(min(lp->min, rp->min), root->data);

    if(mp->isBST)
    {
        mp->largestBSTroot = root;
        mp->largestBSTsize = lp->largestBSTsize + rp->largestBSTsize + 1;
    }
    else if(lp->largestBSTsize > rp->largestBSTsize)
    {
        mp->largestBSTroot = lp->largestBSTroot;
        mp->largestBSTsize = lp->largestBSTsize;
    }
    else
    {
        mp->largestBSTroot = rp->largestBSTroot;
        mp->largestBSTsize = rp->largestBSTsize;
    }

    return mp;
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

    BSTPair* res = checkBST(p);
    cout<<"The size of the largest bst in a bt is : "<<res->largestBSTsize<<endl;
    cout<<"The root of the largest bst in  a bt is : "<<res->largestBSTroot->data;
    return 0;
}
