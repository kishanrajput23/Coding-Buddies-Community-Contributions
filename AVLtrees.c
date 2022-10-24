#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    int height;
    struct Node *left;
    struct Node *right;

} Node;

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d\t", root->key);
        inOrder(root->right);
    }
}

int getHeight(Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

Node *createNode(int key)
{
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->key = key;
    ptr->left = NULL;
    ptr->right = NULL;
    ptr->height = 1;

    return ptr;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int getBalanceFactor(Node *n)
{
    if (n == NULL)
        return 0;

    return getHeight(n->left) - getHeight(n->right);
}

// int max()

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

    return y;
}

Node *insert(Node *bst, int key)
{
    if (bst == NULL)
        return createNode(key);

    if (key < bst->key)
        bst->left = insert(bst->left, key);

    else if (key > bst->key)
        bst->right = insert(bst->right, key);
    return bst;

    bst->height = 1 + max((getHeight(bst->left)), getHeight(bst->right));

    int bf = getBalanceFactor(bst);

    // LL case
    if (bf > 1 && key < bst->left->key)
    {
        rightRotate(bst);
    }
    // RR case
    if (bf < -1 && key > bst->right->key)
    {
        leftRotate(bst);
    }
    // LR case
    if (bf > 1 && key > bst->left->key)
    {
        bst->left = leftRotate(bst->left);
        rightRotate(bst);
    }
    // RL case
    if (bf > 1 && key < bst->right->key)
    {
        bst->right = rightRotate(bst->right);
        leftRotate(bst);
    }

    return bst;
}

int main()
{
    Node *root = NULL;
    root = insert(root, 13);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 8);
    root = insert(root, 9);

    inOrder(root);

    insert(root, 18);
    insert(root, 6);
    printf("\n");
    inOrder(root);
    
    return 0;
}

