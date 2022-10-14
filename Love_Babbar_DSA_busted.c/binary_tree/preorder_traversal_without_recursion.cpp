#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    // public:
    // Node(int val)
    // {
    //     data = val;
    //     left = NULL;
    //     right = NULL;
    // }
};

struct Node *createNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// this is the algorithm to remember 
// rpa algo similar to level order traversal -> remove , print , add === rpa algo 
// time complexity: O(N)
// space compelxity: O(N)
// algo
/*
 SEE TECH DOSE VIDEO 
1. push the root into the stack . 
2. while(stack is not empty )
   1.1 pop and store top node from stack. 
   1.2 print it. 
   1.3 if right then push right. 
   1.4 if left then push left. 
*/

void preorderT(struct Node *root)
{
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        cout << temp->data << " ";
        if (temp->right != NULL)
        {
            s.push(temp->right);
        }
        if (temp->left != NULL)
        {
            s.push(temp->left);
        }
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
    preorderT(p);
    cout << endl;
}
