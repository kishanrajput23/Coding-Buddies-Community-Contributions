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

void leastGreaterOnRight(vector<int> &a)
{
    vector<int> res;
    map<int, int> m;
    for (int i = 0; i < a.size(); i++)
    {
        m[a[i]]= i;
    }
    
    for (int i = 0; i < a.size(); i++)
    {
        auto it = m.upper_bound(a[i]);
        m.erase(a[i]);
        if(it != m.end())
        {
            cout<<it->first<<" ";
            // res.push_back(it->first);
        }
        else
        {
            cout<<-1<<" ";
            // res.push_back(-1);
        }
    }
    // return res;
    
}

int main()
{
    vector<int> a= {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    leastGreaterOnRight(a);
    return 0;
}
