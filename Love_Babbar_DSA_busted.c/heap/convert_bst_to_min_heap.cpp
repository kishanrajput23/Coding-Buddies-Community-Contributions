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

// this approach is made by me 
// algo:
// after looking at various examples I observed that 
// we will do level order traversal and store the elements  before the leaf nodes appear vector
// then I will traverse that vector from back and then traverse diagonally for each element in the vector. 
// and swap the nodes with it. 
// dry run the code to understand better
// time complexity: O(N)
// space complexity: O(N)
void bstToMinHeap(Node *root)
{
    queue<Node *> q;
    q.push(root);
    vector<Node *> v;
    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp->left && temp->right)
        {
            q.push(temp->left);
            q.push(temp->right);
            v.push_back(temp);
        }
        else if (temp->left)
        {
            v.push_back(temp);
            break;
        }
        else if (!root->left && !root->right)
        {
            break;
        }
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i]->data << " ";
    // }
    // cout << endl;

    for (int i = v.size() - 1; i >= 0; i--)
    {
        Node *temp = v[i];
        while (temp->left != NULL)
        {
            swap(temp->data, temp->left->data);
            temp = temp->left;
        }
    }
}

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


// this approach is from gfg 
// this approach is easy to understand 
// ******* property : if we are given a BST then, the inorder traversal of BST is equal to the preorder traversal of the min heap
// inorder(BST) == preorder(minHeap)
// time complexity: O(N)
// space complexity: O(N)
void inorderTraversal(Node* root, vector<int> &v)
{
    if(!root) return;
    inorderTraversal(root->left, v);
    v.push_back(root->data);
    inorderTraversal(root->right, v);
}

void preorderTraversal(Node* root, vector<int> &v, int &i)
{
    if(!root) return;
    root->data = v[i++];
    preorderTraversal(root->left, v, i);
    preorderTraversal(root->right, v, i);

}
void BSTtoMINHEAP(Node* root)
{
    vector<int> v;
    int i = 0;
    inorderTraversal(root, v);
    preorderTraversal(root, v, i);
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
    p1->left = p3;
    // p1->right = p4;
    // p2->right = p5;
    // p4->left = p6;
    // p4->right = p7;
    // p3->right = p8;

    // cout<<check_whether_a_binary_tree_a_balanced_binary_tree_or_not(p);
    // cout << check_if_a_binary_tree_a_heap_or_not(p);
    inorderT(p);
    cout<<endl;
    // bstToMinHeap(p);
    BSTtoMINHEAP(p);
    inorderT(p);
    return 0;
}
