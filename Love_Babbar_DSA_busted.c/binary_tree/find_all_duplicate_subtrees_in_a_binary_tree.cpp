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

// this is an important interview question asked in google interview
// most efficient way to solve this problem
// see code library video for better understanding .
// time complexity: O(N)
// space complexity: O(N)
string duplicateSubtrees(Node *root, map<string, int> &m)
{
    if (root == NULL)
    {
        return "$";
    }

    string s = "";

    s = s + to_string(root->data);
    s = s + duplicateSubtrees(root->left, m);
    s = s + duplicateSubtrees(root->right, m);
    m[s]++;
    return s;
}

void printAllDup(Node* root)
{
    map<string, int> m;
    string s = duplicateSubtrees(root, m);
    
    for(auto x:m)
    {
        if(x.second>=2)
        {
           cout<<x.first<<" ";
        }
    }
}
int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(5);
    struct Node *p5 = createNode(2);
    struct Node *p6 = createNode(4);
    struct Node *p7 = createNode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->right = p5;
    p5->left = p6;
    p5->right = p7;
    
    printAllDup(p);
    return 0;
}
