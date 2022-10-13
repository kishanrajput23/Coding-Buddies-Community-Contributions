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

// Before finding the median of the bst in a O(1) space simply learn morris algo first.
// this is the morris algorithm.
// This is an important algorihtm as it gives inorder traversal of a binary tree
// in O(1) extra space without using recursion stack and stack in the iterative traversal
// time complexity: O(N)
// space complexity: O(1)
// For understanding morris algorithm. see *********pep coding vide***********
// Node *right_most(Node *root, Node *rootl)
// {
//     while (rootl->right != NULL && rootl->right != root)
//     {
//         rootl = rootl->right;
//     }
//     return rootl;
// }
// void morris_inorder_traversal(Node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     Node *curr = root;
//     while (curr != NULL)
//     {
//         if (curr->left == NULL)
//         {
//             cout << curr->data <<" ";
//             curr = curr->right;
//         }
//         else
//         {
//             Node *rightm = right_most(curr, curr->left);
//             if (rightm->right == NULL)
//             {
//                 rightm->right = curr;
//                 curr = curr->left;
//             }
//             else
//             {
//                 rightm->right = NULL;
//                 cout << curr->data << " ";
//                 curr = curr->right;
//             }
//         }
//     }
// }

// the toughest question of the bst . 
// Question: To find the median of the bst in O(1) space.
// there is only one approach to solve this problem in O(1) space .
// by morris inorder traversal in the binary tree.
// first to morris inorder traversal to find the number of nodes in the binary tree
// Then again do morris inorder traversal and maintain the counter such that
// if even nodes then answer will be n/2 and n/2+1 node.
// else then answer will be n+1/2 th node.
Node *right_most(Node *root, Node *rootl)
{
    while (rootl->right != NULL && rootl->right != root)
    {
        rootl = rootl->right;
    }
    return rootl;
}
int morris_inorder_traversal1(Node *root)
{
    int count = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // cout << curr->data <<" ";
            count++;
            curr = curr->right;
        }
        else
        {
            Node *rightm = right_most(curr, curr->left);
            if (rightm->right == NULL)
            {
                rightm->right = curr;
                curr = curr->left;
            }
            else
            {
                rightm->right = NULL;
                // cout << curr->data << " ";
                count++;
                curr = curr->right;
            }
        }
    }
    return count;
}

void checkCount(Node *curr, int &count, int &a, int &b, int n)
{
    if (count == (n / 2))
    {
        a = curr->data;
    }
    if (count == (n / 2) + 1)
    {
        b = curr->data;
    }
}
void morris_inorder_traversal_even(Node *root, int &a, int &b, int n)
{
    if (root == NULL)
    {
        return;
    }
    int count = 0;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            // cout << curr->data <<" ";
            count++;
            checkCount(curr, count, a, b, n);
            curr = curr->right;
        }
        else
        {
            Node *rightm = right_most(curr, curr->left);
            if (rightm->right == NULL)
            {
                rightm->right = curr;
                curr = curr->left;
            }
            else
            {
                rightm->right = NULL;
                // cout << curr->data << " ";
                count++;
                checkCount(curr, count, a, b, n);
                curr = curr->right;
            }
        }
    }
}

float medianOfBST(Node *root)
{
    int a, b;
    int n = morris_inorder_traversal1(root);
    // cout << n << endl;these couts are to check my answer and the code no need of them
    morris_inorder_traversal_even(root, a, b, n);
    // cout << "a" << a << endl;
    // cout << "b" << b << endl;
    if (n % 2 == 0)
    {
        return (a + b) / 2.0;
    }
    else
    {
        return (float)b;
    }
}

int main()
{
    struct Node *p = createNode(3);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(1);
    struct Node *p3 = createNode(4);
    // struct Node *p4 = createNode(5);

    p->left = p1;
    p->right = p3;
    p1->left = p2;
    // p3->right = p4;
    float medianIs = medianOfBST(p);
    cout << medianIs;

    return 0;
}
