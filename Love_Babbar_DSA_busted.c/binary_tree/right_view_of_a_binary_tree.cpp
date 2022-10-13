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

// worst case
//use reverse level order traversal and print the first element of each level from the riht .
// time complexity: O(N)
// space complexity: O(2**h) where h is the height of the binary tree.
// void rightView(struct Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     queue<Node *> q;
//     q.push(root);
//     q.push(NULL);
//     bool flag = true;
//     while (q.size() != 1)
//     {
//         Node *temp = q.front();
//         q.pop();
//         if (temp != NULL)
//         {
//             if (temp->right != NULL)
//             {
//                 q.push(temp->right);
//             }

//             if (temp->left != NULL)
//             {
//                 q.push(temp->left);
//             }

//             if (flag)
//             {
//                 flag = false;
//                 cout << temp->data << " ";
//             }
//         }
//         else
//         {
//             q.push(NULL);
//             flag = true;
//         }
//     }
// }

//approach 2:
// see the tech dose video for better understanding 
// time complexity: O(N)
// space complexity: O(h) h is the height of the tree.
// algo 
// create a utility function rightViewUtil 
// maintain a level array of boolean false
// if the level is currenty false then we are visiting that level for the first time 
// then print that and put that level  to the true. 
void rightViewUtil(Node *root, bool *level, int curr)
{
    if (!root)
    {
        return;
    }

    if (level[curr] == false)
    {
        level[curr] = true;
        cout << root->data << " ";
    }

    rightViewUtil(root->right, level, curr + 1);
    rightViewUtil(root->left, level, curr + 1);
}

void rightView(Node* root)
{
    bool level[]= {false};
    rightViewUtil(root, level, 0);
}
int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(6);
    struct Node *p4 = createNode(7);
    struct Node *p5 = createNode(8);

    p->left = p1;
    p->right = p2;
    p2->left = p3;
    p2->right = p4;
    p4->left = p5;

    rightView(p);
    return 0;
}