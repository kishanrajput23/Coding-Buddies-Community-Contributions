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
// time complexity: O(N)
// space complexity: O(2**h) where h is the height of the binary tree. 
// void leftView(struct Node *root)
// {
//     if(root == NULL)
//     {
//         return;
//     }
//     queue<struct Node *> q;
//     q.push(root);
//     q.push(NULL);
//     bool flag = true;
//     while (q.size() != 1)
//     {
//         Node *temp = q.front();
//         q.pop();
//         if (temp != NULL)
//         {
//             if (flag)
//             {
//                 cout << temp->data << " ";
//                 flag = false;
//             }
//             if (temp->left != NULL)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right != NULL)
//             {
//                 q.push(temp->right);
//             }
//         }
//         else
//         {
//             q.push(temp);
//             flag = true;
//         }
//     }
// }

// approach 2: more efficient than the first one . 
// see the tech dose video for better understanding . 
// time complexity: O(N)
// space complexity: O(H)  height of the binary tree. 
void leftViewUtil(Node* root, bool* level, int curr, vector<int> &a)
{
    if(root == NULL)
    {
        return;
    }

    if(level[curr]== false)
    {
        level[curr]= true;
        // cout<<root->data<<" ";
        a.push_back(root->data);
    }

    leftViewUtil(root->left, level, curr+1, a);
    leftViewUtil(root->right, level, curr+1, a);
}

vector<int> leftView(Node* root)
{
    bool level[]= {false};
    vector<int> a;
    leftViewUtil(root, level, 0, a);

    // for (int i = 0; i < a.size(); i++)
    // {
    //     cout<<a[i]<< " ";
    // }
    return a;
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

    leftView(p);
    return 0;
}