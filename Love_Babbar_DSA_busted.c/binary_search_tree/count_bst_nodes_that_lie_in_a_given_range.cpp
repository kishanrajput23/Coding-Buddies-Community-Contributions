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

// did it myself . 
// time complexity: O(N)
// space complexity: O(H)
void countIt(Node* root, int l,int h, int &count)
{
    if(!root) return;
    countIt(root->left, l, h, count);
    if(l<= root->data && root->data<=h) count++;
    countIt(root->right, l, h, count);
}
int getCount(Node *root, int l, int h)
{
    int count =0;
    countIt(root, l, h, count);
    return count;
  // your code goes here   
}

int main()
{
    struct Node *p = createNode(10);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    int count = getCount(p, 5, 20);
    cout<<count;
    return 0;
}
