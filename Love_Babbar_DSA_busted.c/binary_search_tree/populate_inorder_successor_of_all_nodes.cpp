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

// we need to populate all of the inorder successor in a binary tree.
// time complexity: O(N)
// space complexity: O(H)
void inorderSuccessorUtil(Node *root, int &prev)
{
    if (root == NULL)
    {
        return;
    }
    inorderSuccessorUtil(root->left, prev);
    if (prev != INT_MIN)
    {
        cout << prev << "->" << root->data << " ";
    }
    prev = root->data;
    inorderSuccessorUtil(root->right, prev);
}
void inorderSuccessor(Node *root)
{
    if (root == NULL)
    {
        cout << "As the root is NULL so there is no inorder successor " << endl;
        return;
    }
    int prev = INT_MIN;
    inorderSuccessorUtil(root, prev);
    cout<<" "<<prev<<"->"<<-1;
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

    inorderSuccessor(p);
    return 0;
}
