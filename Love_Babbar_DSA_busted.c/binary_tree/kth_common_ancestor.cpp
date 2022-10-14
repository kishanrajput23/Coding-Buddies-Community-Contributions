#include <bits/stdc++.h>
using namespace std;
// I have done three problems here before doing lca question before this approach helps to traverse through all the paths from the root to any node of the binary tree.

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



// approach 2:
// I did it myself 
// time complexity: O(N)
//space complexity: O(H)
// where h is the height of the tree , 
//simply find the path of that node and then simply print that ancestor from the vector 
void kth_ancestor_of_binary_tree(Node *root, vector<Node *> &v, int &k, int &val)
{
    if (!root)
    {
        return;
    }

    v.push_back(root);
    kth_ancestor_of_binary_tree(root->left, v, k, val);
    kth_ancestor_of_binary_tree(root->right, v, k, val);

    if (root->data == val)
    {
   
        if (v.size() - 1 - k >= 0)
        {
            cout << v[v.size() - 1 - k]->data;
        }
        else{
            cout<<"-1";
        }
    }
    v.pop_back();
}

int main()
{
    struct Node *p = createNode(1);
    struct Node *p1 = createNode(2);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(3);
    struct Node *p5 = createNode(7);
    struct Node *p6 = createNode(5);
    struct Node *p7 = createNode(8);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p4->left = p6;
    p5->right = p7;

    vector<Node *> v;
    int val = 3;
    int k = 3;
    kth_ancestor_of_binary_tree(p, v, k, val);

    return 0;
}
