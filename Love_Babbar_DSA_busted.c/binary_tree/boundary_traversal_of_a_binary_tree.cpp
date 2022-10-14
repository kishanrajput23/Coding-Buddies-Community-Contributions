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

// this approach is by me
// algo : -
// make a separate function name rootNode this function calculates all the leaf nodes present in a tree
// store them in a queue
// after that left most line of the tree and print all the elements
// until we reach the left most node
// after that print all the elements of the queue until size 1
// then again traverse through the right most tree and then store them in a stack and then at last print them

// time complexity: O(N)
// space complexity: O(N)
void rootNode(Node *root, queue<Node *> &q)
{
    if (!root)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        q.push(root);
        return;
    }

    rootNode(root->left, q);
    rootNode(root->right, q);
}

void boundaryTraversal(Node *root)
{

    if (!root)
        return;

    stack<Node *> s;
    queue<Node *> q;
    rootNode(root, q);
    Node *temp = root;

    while (temp != q.front())
    {
        if (temp->left != NULL)
        {
            cout << temp->data << " ";
            temp = temp->left;
        }
        else if (temp->right != NULL)
        {
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    while (q.size() != 1)
    {
        Node *ptr = q.front();
        cout << ptr->data << " ";

        q.pop();
    }

    temp = root->right;

    while (temp != q.front())
    {
        // if(temp == NULL)
        // {
        //     break;
        // }
        if (temp->right != NULL)
        {
            s.push(temp);
            temp = temp->right;
        }
        else if (temp->left != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }

    s.push(temp);
    q.pop();

    while (!s.empty())
    {
        Node *pp = s.top();
        cout << pp->data << " ";

        s.pop();
    }
}

int main()
{
    struct Node *p = createNode(20);
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
    p1->right = p4;
    p2->right = p5;
    p4->left = p6;
    p4->right = p7;
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
    // diagonalTraversal(p);

    boundaryTraversal(p);

    return 0;
}