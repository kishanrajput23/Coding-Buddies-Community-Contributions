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

// this is a hard problem to understand 
// tree isomorphism problem 
// time complexity: O(n)
// space complexity: O(H)
// see coding simplified video for better understanding 
// isomorphism : It's a combination of mirror structure and same structure 
// left--left and right--right, or, left--right and right--left 
bool isomorph(Node *root1, Node *root2)
{
    if (root1 == NULL and root2 == NULL)
    {
        return true;
    }

    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if (root1->data != root2->data)
    {
        return false;
    }

    return ((isomorph(root1->left, root2->left) && isomorph(root1->right, root2->right)) || (isomorph(root1->left, root2->right) && isomorph(root1->right, root2->left)));
}
int main()
{
    Node *p = createNode(1);
    Node *p1 = createNode(2);
    Node *p2 = createNode(3);
    p->left = p1;
    p->right = p2;

    Node *q = createNode(1);
    Node *q1 = createNode(3);
    Node *q2 = createNode(2);
    q->left = q1;
    q->right = q2;

    cout << isomorph(p, q);
    return 0;
}
