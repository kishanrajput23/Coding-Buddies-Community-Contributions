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

// approach 1: 
// we could simply traverse through both the trees 
// first with level order and second with reverse level order 
// and store them in the vector
// after then check if each element of both the vectors are same or not 
// if they are same then return 1 else return 0
//time complexity:O(N)
// space complexity: O(N)


//approach 2: 
// seen from code simplified you tube channel 
// time complexity: O(N)
// space complexity: O(N)
bool check(Node* root1, Node* root2)
{
    if(root1 == NULL and root2== NULL)
    {
        return true;
    }

    if(root1 == NULL || root2 == NULL)
    {
        return false;
    }

    if(root1->data == root2->data && check(root1->left, root2->right) && check(root1->right, root2->left))
    {
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    Node* p = createNode(1);
    Node* p1 = createNode(2);
    Node* p2 = createNode(3);

    p->left = p1;
    p->right = p2;
    Node* q = createNode(1);
    Node* q1 = createNode(3);
    Node* q2 = createNode(2);

    q->left = q1;
    q->right = q2;

    cout<<check(p, q)<<endl;
    return 0;
}