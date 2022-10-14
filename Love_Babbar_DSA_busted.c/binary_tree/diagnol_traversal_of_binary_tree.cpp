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

// this code is written by me but it seems complext so I have learnt code from code library video 
// time complexity: O(N) each node is visited max two times. 
// space complexity: O(N)
// void diagonalTraversal(Node *root)
// {
//     if (!root)
//     {
//         return;
//     }
//     if(root->left == NULL && root->right == NULL){
//         cout<<root->data<<" ";
//         return;
//     }
//     queue<Node *> q;
//     while (root->left != NULL || root->right != NULL || !q.empty())
//     {
//         while (root->left == NULL && root->right == NULL)
//         {
//             cout << root->data << " ";
//             // root = root->right;
//             if (q.empty())
//             {
//                 break;
//             }
//             root = q.front();
//             q.pop();
//         }
//         if(q.empty() && root->left == NULL && root->right == NULL)
//         {
//             break;
//         }
//         if (root->left != NULL )
//         {
//             q.push(root->left);
//         }
//         cout << root->data << " ";
//         root = root->right;
//     }
// }

// this is the simpler code written by code library video 
// time compelxity: O(n)
// space complexity: O(N)
void diagonalTraversal(Node* root)
{
    if(!root)
    {
        return;
    }

    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            if(temp->left != NULL)
            {
                q.push(temp->left);
            }

            temp= temp->right;
        }
    }
}
int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(4);
    struct Node *p2 = createNode(2);
    struct Node *p3 = createNode(7);
    struct Node *p4 = createNode(6);
    struct Node *p5 = createNode(5);
    struct Node *p6 = createNode(3);
    struct Node *p7 = createNode(9);
    struct Node *p8= createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p3->left = p7;
    p3->right = p8;

    // inorderT(p);
    // cout << endl;
    // struct Node *ptr = remove(p, 5);
    // inorderT(p);

    // vector<int> a = reverse_level_order_traversal(p);
    // for (auto i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << height(p) << endl;
    // cout << diameter(p) << endl;
    // DiaPair* a = diameter1(p);
    // cout << a->dia << endl;
    diagonalTraversal(p);
    return 0;
}