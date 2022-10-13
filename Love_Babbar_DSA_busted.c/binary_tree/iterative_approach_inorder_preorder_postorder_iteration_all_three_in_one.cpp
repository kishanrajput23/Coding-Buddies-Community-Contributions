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


void iterative_approach_to_print_inorder_preorder_postorder(Node *root)
{
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    stack<pair<Node *, int>> s;
    s.push({root, 1});
    while (!s.empty())
    {
        pair<Node *, int> temp = s.top();
        if (temp.second == 1)
        {
            preorder.push_back(temp.first->data);
            // temp.second++; // if I use this then it will not work so we need to do this by s.top()
            s.top().second++;
            if (temp.first->left != NULL)
            {
                s.push({temp.first->left, 1});
            }
        }
        else if (temp.second == 2)
        {
            inorder.push_back(temp.first->data);
            s.top().second++;
            if (temp.first->right != NULL)
            {
                s.push({temp.first->right, 1});
            }
        }
        else
        {
            postorder.push_back(temp.first->data);
            s.pop();
        }
    }

    for (int i = 0; i < preorder.size(); i++)
    {
        // cout << "Printing preorder sequence :" << endl;
        cout << preorder[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < inorder.size(); i++)
    {
        // cout << "Printing inorder sequence :" << endl;
        cout << inorder[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < postorder.size(); i++)
    {
        // cout << "Printing postorder sequence :" << endl;
        cout << postorder[i] << " ";
    }
    cout << endl;
}
int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(8);
    struct Node *p2 = createNode(12);
    struct Node *p3 = createNode(7);
    struct Node *p4 = createNode(6);

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
    // cout << height(p) << endl;
    // cout << diameter(p) << endl;
    // inorderT(p);
    // postorderT(p);
    // cout << endl;
    // struct Node *ptr = mirror(p);
    // mirror(p);
    // cout << ptr << endl;
    // inorderT(p);

    // DiaPair* a = diameter1(p);
    // cout << a->dia << endl;

    // stack<pair<Node *, int>> s;
    // s.push({p, 1});
    // // cout << s.top().first->data<< endl;

    // pair<Node *, int> temp = s.top();
    // temp.second++;
    // cout << temp.first->data << " ";
    // cout << temp.second;
    // // if valid
    // s.push({temp.first->left, 1});

    iterative_approach_to_print_inorder_preorder_postorder(p);
    return 0;
}