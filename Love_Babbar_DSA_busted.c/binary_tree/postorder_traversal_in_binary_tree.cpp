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

// this is same as the preorder_traversal without recursion just there is a little change firstly push left and then push right
// also use another stack to store the resultant we had done this because if we will not use this then postorder traversal answer will be reversed
// time complexity: O(N)
// space complextiy: O(N)
// algo see tech dose video
// 1. create two empty stacks s and res
// 2. push root element in the stack s
// 3. then while stack s is not empty
// 4. pop from the s and push it in the res
// 5. then push that popped element left and then right into the stack s if exists
// 6. after that while res is not empty print and pop the elements.
void postorderT(struct Node *root)
{
    stack<Node *> s;   // same as done in preorder
    stack<Node *> res; // to store the resultant
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        res.push(temp);
        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
        if (temp->right != NULL)
        {
            s.push(temp->right);
        }
    }

    while (!res.empty())
    {
        Node *result = res.top();
        cout << result->data << " ";
        res.pop();
    }
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

    stack<pair<Node *, int >> s;
    s.push({p, 1});
    // cout << s.top().first->data<< endl;

    pair<Node*, int> temp = s.top();
    temp.second++;
    cout<<temp.first->data<<" ";
    cout<<temp.second;
    // if valid 
    s.push({temp.first->left, 1});
    return 0;
}