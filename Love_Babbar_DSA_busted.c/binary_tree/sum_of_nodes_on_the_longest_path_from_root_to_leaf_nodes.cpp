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

// time complexity: O(N)
// space complexity: O(2^h) h is the height of the tree . 
// appraoch : simply find all the root nodes and store them in a vector pair with element, level 
// then check for each of them . wheter their v[i].second is equal or not. 
void checkUtil(Node *root, vector<pair<int, int>> &v, int lvl)
{
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back({root->data, lvl});
        return;
    }

    if (root->left)
    {
        checkUtil(root->left, v, lvl + 1);
    }
    if (root->right)
    {
        checkUtil(root->right, v, lvl + 1);
    }
}

bool check(Node *root)
{
    if (!root)
        return true;

    vector<pair<int, int>> v;
    int lvl = 0;
    checkUtil(root, v, lvl);

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i].second != v[i + 1].second)
        {
            return false;
        }
    }

    return true;
}

int ht1(Node* root)
{
    if(!root)
    {
        return 0;
    }

    int lht = ht1(root->left);
    int rht = ht1(root->right);
    int mht = max(lht, rht)+1;

    if(lht>rht)
    {
        s.push(root->left);
    }
    else
    {
        s.push(root->right);
    }

    return mht;
}

int ht2(Node* root)
{
    Node* temp = root;

    while(temp != NULL)
    {
        if(temp->left->data>temp->right->data)
        {
            s.push(temp->left);
        }
        else{
            s.push(temp->right);
        }
    }
}
int main()
{
    struct Node *p = createNode(0);
    struct Node *p1 = createNode(20);
    struct Node *p2 = createNode(-40);
    // struct Node *p3 = createNode(10);
    // struct Node *p4 = createNode(10);

    p->left = p1;
    p->right = p2;
    // p1->left = p3;
    // p1->right = p4;
    cout << check(p);
    return 0;
}
