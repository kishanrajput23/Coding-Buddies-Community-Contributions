#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

struct Node
{
    int data;
    int hd;
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

// see tech dose video
// it's an important question it's the vertical order traversal
// time complexity: O((log(n))*(log(n))*log(n)*n)
// // space complexity: O(rows*columns*N)
// void vertical_order_util(Node *root, int col, int row, map<int, map<int, multiset<int>>> &m)
// {
//     if (root == NULL)
//     {
//         return;
//     }

//     m[col][row].insert(root->data);
//     vertical_order_util(root->left, col - 1, row + 1, m);
//     vertical_order_util(root->right, col + 1, row + 1, m);
// }
// void vertical_order_traversal(Node *root)
// {
//     map<int, map<int, multiset<int>>> m;
//     int col = 0;
//     int row = 0;
//     vertical_order_util(root, col, row, m);

//     for (auto it = m.begin(); it != m.end(); it++)
//     {
//         for (auto iter = it->second.begin(); iter != it->second.end(); iter++)
//         {
//             for (auto s = iter->second.begin(); s != iter->second.end(); s++)
//             {
//                 cout << (*s) << " ";
//             }
//         }
//     }

//     // either use this to print the numbers

//     // for (auto m1 : m)
//     // {
//     //     for(auto m2 : m1.second)
//     //     {
//     //         for(auto m3 : m2.second)
//     //         {
//     //              cout<< m3<<" ";
//     //         }
//     //     }
//     // }
// }

void bottomview(Node *root)
{
    if (!root)
    {
        return;
    }

    queue<pair<Node *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        Node *temp = q.front().first;
        int h = q.front().second;
        q.pop();
        m[h] = temp->data;

        if (temp->left != NULL)
        {
            q.push({temp->left, h - 1});
        }
        if (temp->right != NULL)
        {
            q.push({temp->right, h + 1});
        }
    }
    for(auto x: m)
    {
        cout<<x.second<<" ";
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
    bottomview(p);
    return 0;
}