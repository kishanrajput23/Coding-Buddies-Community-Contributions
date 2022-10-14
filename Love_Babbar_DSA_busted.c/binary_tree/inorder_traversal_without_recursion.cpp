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


// remember the algo
// time complexity: O(N)
// space complexity: O(N) // for skewed binary tree. 
// good problem 
// see tech dose video for revision also for the dry run of this program. 
/*
1. create an empty stack. 
2. Initialize curr node to the root. 
3. push current element to the left and set curr to the left. 
4. if curr is NULL and s not empty: 
    1.1pop top of s and print it. 
    1.2 set current popped node the right of it. 
    1.3 go to step 3. 
5. If curr is equal to NULL and s is empty than we are done. 
*/
void inorderT(struct Node *root)
{
    stack<struct Node *> s;
    struct Node *curr = root;
    do
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = s.top();
            curr = curr->right;
            struct Node *temp = s.top();
            cout << temp->data << " ";
            s.pop();
        }
    } while (!s.empty() || curr != NULL);
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
    inorderT(p);
    // cout << endl;
    // struct Node *ptr = mirror(p);
    // mirror(p);
    // cout << ptr << endl;
    // inorderT(p);

    // DiaPair* a = diameter1(p);
    // cout << a->dia << endl;
    return 0;
}