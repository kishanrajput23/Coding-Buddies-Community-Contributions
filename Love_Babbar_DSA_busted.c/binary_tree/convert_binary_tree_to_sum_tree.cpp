#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

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

void inorderT(Node* root)
{
    if(!root)
    {
        return;
    }

    inorderT(root->left);
    cout<<root->data<<" ";
    inorderT(root->right);
}
struct Node *createNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// approach 1: brute force 
// written by me 
// time complexity: O(N^N)
// space complexity: O(H^H)
// algo : 
// simply calculate the sum for each below subtrees and replace them with the data of the root. 
// int sum(Node* root)
// {
//     if(!root)
//     {
//         return 0;
//     }

//     int ls = sum(root->left);
//     int rs = sum(root->right);
//     int ts = ls + rs + root->data;
//     return ts;
// }

// void sumTreeUtil(Node* root)
// {
//     if(!root) return;

//     int lst = sum(root->left);
//     int rst = sum(root->right);
//     root->data = lst + rst;
    
//     sumTreeUtil(root->left);
//     sumTreeUtil(root->right);
// }

// void sumTree(Node* root)
// {
//     if(!root)
//     {
//         return ;
//     }

//    int data = sumTreeUtil(root);

// }

// approach 2: efficient approach 
// written by code with library 
// time complexity: O(N)
// space complexity: O(H)
int sumTreeUtil(Node* root)
{
    if(!root)
    {
        return 0;
    }

    int ls = sumTreeUtil(root->left);
    int rs = sumTreeUtil(root->right);
    int x = root->data;
    root->data = ls + rs;
    int sum = ls + rs + x;
    return sum;
}
void sumTree(Node* root)
{
    int store = sumTreeUtil(root);
}
int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    // sumTreeUtil(p);
    sumTree(p);
    inorderT(p);
    return 0;
}
