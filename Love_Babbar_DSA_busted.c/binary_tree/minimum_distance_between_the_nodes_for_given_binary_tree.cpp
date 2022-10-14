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


// approach 1: this approach is similar to the appraoch for lca 
// find all the paths and store them as vectors and then find the required result 
//time complexity: O(N)
// space complexity: O(N)
// void util(Node *root, vector<Node *> &v, int n, int &f)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     if (f)
//     {
//         v.push_back(root);
//     }

//     util(root->left, v, n, f);
//     util(root->right, v, n, f);

//     if (n == root->data)
//     {
//         f = 0;
//     }
//     if (f)
//     {
//         v.pop_back();
//     }
// }

// int distance_between_nodes(Node *root, int n1, int n2)
// {
//     vector<Node *> path1, path2;
//     int f = 1;
//     util(root, path1, n1, f);
//     int fl = 1;
//     util(root, path2, n2, fl);

//     if(path1.size()==0 or path2.size()==0)
//     {
//         return -1;
//     }
//     int i = 0;
//     int j = 0;
//     while (1)
//     {
//         if (i == path1.size())
//         {
//             break;
//         }
//         if(j == path2.size())
//         {
//             break;
//         }
//         if (path1[i]->data != path2[j]->data)
//         {
//             break;
//         }
//         i++;
//         j++;
//     }
//     int count =0;
//     int path1Sum = i;
//     while(path1Sum != path1.size())
//     {
//         path1Sum++;
//         count++;
//     }

//     int path2Sum = j;
//     while(path2Sum != path2.size())
//     {
//         path2Sum++;
//         count++;
//     }
//     return count;
// }

// approach 2: 
// find the lca of the given two nodes then sum the paths for each of them 
// see code library video for better understanding. 
// time complexity: O(N)
//space complexity: O(N)
Node* lca(Node* root, int n1, int n2)
{
    if(!root) return NULL;
    if(root->data == n1 or root->data == n2) return root;
    Node* l = lca(root->left, n1, n2);
    Node* r = lca(root->right, n1, n2);

    if(l and r) return root;

    if(l) return l;
    else return r;
}

int distanceBetweenRootAndNode(Node* root, int n)
{
    if(!root) return 0;
    if(root->data == n) return 1;
    int ldistance = distanceBetweenRootAndNode(root->left, n);
    int rdistance= distanceBetweenRootAndNode(root->right, n);

    if(!ldistance and !rdistance) return 0;
    return ldistance+ rdistance+1; 
}
int mDBN(Node* root, int n1, int n2)
{
    Node* lowestCA = lca(root, n1, n2);
    int ld = distanceBetweenRootAndNode(lowestCA, n1);
    int rd = distanceBetweenRootAndNode(lowestCA, n2);

    return ld + rd-2;
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


    int n1 = 5;
    int n2 = 7;
    cout<<mDBN(p, n1, n2);

    return 0;
}
