#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

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

void inorderT(Node *root)
{
    if (!root)
    {
        return;
    }

    inorderT(root->left);
    cout << root->data << " ";
    inorderT(root->right);
}

//this is the best approach to solve this problem
// see code library video
// time complexity: O(N)
// space complexity: O(H) H : is the height of the tree (it's for the recursion stack)
// algo
// simply do a inorder traversal as the question asks for the inorder DLL .
// maintain a prev pointer which stores the addresses of the prev node
// and if visiting the first node of the future DLL then point head to that root and also prev = root
// otherwise prev->right = root and prev->right->left= prev

// AN IMPORTANT NOTE
// it's for the language
// we could use Node** head or Node* &head
// if using Node** head then in function we need to use (*head)
// and if we use Node* &head then in function we need to use head only.
// similarly for prev and f
void binaryTreeToDLLUtil(Node *root, Node **head, Node **prev, int *f)
{
    if (!root)
    {
        return;
    }

    binaryTreeToDLLUtil(root->left, head, prev, f);

    if ((*f) == 0)
    {
        (*f) = 1;
        (*head) = root;
        (*prev) = root;
    }
    else
    {
        (*prev)->right = root;
        (*prev)->right->left = (*prev);
        (*prev) = root;
    }

    binaryTreeToDLLUtil(root->right, head, prev, f);
}

Node *binaryTreeToDLL(Node *root)
{
    if (!root)
    {
        return NULL;
    }

    Node *head = NULL;
    Node *prev = NULL;
    int f = 0;
    binaryTreeToDLLUtil(root, &head, &prev, &f);
    return head;
}

void printDLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->right;
    }
}
int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(3);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(5);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    inorderT(p);
    cout << endl;
    Node *head = binaryTreeToDLL(p);
    printDLL(head);
    return 0;
}
