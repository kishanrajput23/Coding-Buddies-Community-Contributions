#include <bits/stdc++.h>
using namespace std;
//

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

// before solving this quoestion you need to solve another quoestion
// to check whether a given binary tree is a complete binary tree or not.
// time complexity: o(N)
// space compelxity: O(N)
// algo
// the idea is to do a level order traversal
// if we are not getting a full node then set the flag to 1
// and if we visit the node again with either left or right child then simply return that it's not complete binary tree.
//**** see gfg article for better understanding*****.
// this approach is not intitutive need to remember it. 
bool check_whether_a_binary_tree_a_balanced_binary_tree_or_not(Node *root)
{
    if (!root)
        return true;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        bool flag = false;
        if (temp->left)
        {
            if (flag == true)
            {
                return false;
            }
            q.push(temp->left);
        }
        else
        {
            flag= true;
        }

        if(temp->right)
        {
            if(flag == true)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            flag = true;
        }
    }
    return true;
}


// the above approach can be extended to check whether a given binary tree is a heap or not 
// heap conditions
// the given binary tree must be a complete binary tree
// the root->data> root->left->data and root->data> root->right->data
// time complexity: O(N)
// space complexity: O(N)
bool check_if_a_binary_tree_a_heap_or_not(Node* root)
{
    if(!root) return true;

    queue<Node*> q;
    q.push(root);
    bool flag = false;
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp->left)
        {
            if(flag == true || root->data<=temp->left->data)
            {
                return false;
            }

            q.push(temp->left);
        }
        else
        {
            flag = true;
        }

        if(temp->right)
        {
            if(flag == true || root->data<=temp->right->data)
            {
                return false;
            }
            q.push(temp->right);
        }
        else
        {
            flag = true;
        }
    }
    return true;
}
int main()
{
    struct Node *p = createNode(40);
    struct Node *p1 = createNode(8);
    struct Node *p2 = createNode(22);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(12);
    struct Node *p5 = createNode(25);
    struct Node *p6 = createNode(10);
    struct Node *p7 = createNode(14);
    struct Node *p8 = createNode(30);

    p->left = p1;
    p->right = p2;
    // p1->left = p3;
    // p1->right = p4;
    // p2->right = p5;
    // p4->left = p6;
    // p4->right = p7;
    // p3->right = p8;

    // cout<<check_whether_a_binary_tree_a_balanced_binary_tree_or_not(p);
    cout<<check_if_a_binary_tree_a_heap_or_not(p);
    return 0;
}