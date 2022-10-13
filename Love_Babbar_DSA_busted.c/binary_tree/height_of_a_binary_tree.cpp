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

void inorderT(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

// time complexity: O(N)
// space complexity: O(1)
int sizeofbinarytree(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ls = sizeofbinarytree(root->left);
    int rs = sizeofbinarytree(root->right);
    int ts = ls + rs + 1;
    return ts;
}

// time complexity: O(N)
// space compllexity: O(1)
int sumOfAllElementsOfTheBinaryTree(struct Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lsm = sumOfAllElementsOfTheBinaryTree(root->left);
    int rsm = sumOfAllElementsOfTheBinaryTree(root->right);
    int tsm = lsm + rsm + root->data;
    return tsm;
}

// time complexity : O(N)
// space complexity: O(1)
int max_element_in_binary_tree(struct Node *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    int lmax = max_element_in_binary_tree(root->left);
    int rmax = max_element_in_binary_tree(root->right);
    int fmax = max(max(lmax, rmax), root->data);
    return fmax;
}

// write a program to find the height of a binary tree.
// time complexity: O(N)
// space complexity: O(N)
// finding height of a binary tree is same as level-order traversal just we need to maintain a NULL ptr so that we could know when a level is finished and hence we can increase the count of the variable.
// int height_of_a_binary_tree(struct Node *root)
// {
//     queue<struct Node *> q;
//     q.push(root);
//     q.push(NULL);
//     int count = 1;
//     while (!q.empty())
//     {
//         struct Node *temp = q.front();
//         q.pop();
//         // cout << temp->data << " ";
//         if (temp == NULL)
//         {
//             if (!q.empty())
//             {
//                 q.push(NULL);
//                 count++;
//             }
//         }
//         else
//         {
//             if (temp->left != NULL)
//             {
//                 q.push(temp->left);
//             }
//             if (temp->right != NULL)
//             {
//                 q.push(temp->right);
//             }
//         }
//     }
//     return count;
// }

// optimised approach to find height of a tree
// time complexity: O(N)
// space complextiy: O(1)
int height_of_binary_tree(struct Node *root)
{
    if (root == NULL)
    {
        return 0; // if we are calculating the height with respect to the nodes.
        // return -1; // if we are calculating the height with respect to the edges.
    }

    int lh = height_of_binary_tree(root->left);
    int rh = height_of_binary_tree(root->right);
    int mh = max(lh, rh) + 1;
    return mh;
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

    // inorderT(p);
    // cout << endl;
    // struct Node *ptr = remove(p, 5);
    // inorderT(p);

    // vector<int> a = reverse_level_order_traversal(p);
    // for (auto i = 0; i < a.size(); i++)
    // {
    //     cout << a[i] << " ";
    // }

    cout << height_of_binary_tree(p) << endl;
    cout << sizeofbinarytree(p) << endl;
    cout << sumOfAllElementsOfTheBinaryTree(p) << endl;
    cout << max_element_in_binary_tree(p) << endl;
    return 0;
}