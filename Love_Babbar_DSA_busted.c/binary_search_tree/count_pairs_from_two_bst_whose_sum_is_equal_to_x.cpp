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

void storeThem(Node *root, unordered_map<int, int> &m)
{
    static int count = 0;
    if (!root)
    {
        return;
    }
    storeThem(root->left, m);
    m[root->data] = count;
    count++;
    storeThem(root->right, m);
}

void PIt(Node *root, unordered_map<int, int> &m, int x)
{
    if (!root)
    {
        return;
    }
    PIt(root->left, m, x);
    if (m.find(x-root->data) != m.end())
    {
        cout << "[" << root->data << ", " << x - root->data << "]"
             << " ";
    }
    PIt(root->right, m, x);
}
void cPairs(Node *root1, Node *root2, int x)
{
    unordered_map<int, int> m;
    storeThem(root2, m);
    PIt(root1, m, x);
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(7);
    struct Node *p3 = createNode(2);
    struct Node *p4 = createNode(4);
    struct Node *p5 = createNode(6);
    struct Node *p6 = createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;

    struct Node *q = createNode(10);
    struct Node *q1 = createNode(6);
    struct Node *q2 = createNode(15);
    struct Node *q3 = createNode(3);
    struct Node *q4 = createNode(8);
    struct Node *q5 = createNode(11);
    struct Node *q6 = createNode(18);

    q->left = q1;
    q->right = q2;
    q1->left = q3;
    q1->right = q4;
    q2->left = q5;
    q2->right = q6;

    cPairs(p, q, 16);
    return 0;
}
