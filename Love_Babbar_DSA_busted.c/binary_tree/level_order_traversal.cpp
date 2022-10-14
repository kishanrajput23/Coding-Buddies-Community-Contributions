#include <bits/stdc++.h>
using namespace std;

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

vector<int> level_order_traversal(struct Node *root)
{
    // if(root== NULL){
    //     return ;
    // }
    queue<struct Node *> q;
    vector<int> a;

    q.push(root);
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();
        a.push_back(temp->data);
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
    }

    return a;
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

    vector<int> a = level_order_traversal(p);
    for (auto i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}