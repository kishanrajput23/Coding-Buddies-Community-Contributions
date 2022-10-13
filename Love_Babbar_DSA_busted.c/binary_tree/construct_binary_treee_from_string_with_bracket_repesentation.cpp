#include <bits/stdc++.h>
using namespace std;
// I will solve four questions in this height of tree questions as they are very similar.

struct Node
{
public:
    char data;
    struct Node *left;
    struct Node *right;

    Node(char val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// struct Node *createNode(int data)
// {
//     struct Node *n = new Node();
//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
// }

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

// time complexity: O(N^N )
//space complexity: O(N)
Node *convert(string st, int s, int e)
{
    // int temp = (int)st[s];
    stack<char> a;
    Node *root = new Node(st[s]);
    bool flag = false;
    int ns, ne;

    for (int i = s + 1; i <= e; i++)
    {
        if (st[i] == '(')
        {
            a.push(i);
        }
        else if (st[i] == ')')
        {
            if (a.size() == 1)
            {
                ns = a.top();
                ne = i;
            }

            a.pop();
        }
        else
        {
            continue;
        }

        if (a.empty())
        {
            if (flag == false)
            {
                flag = true;
                root->left = convert(st, ns + 1, ne - 1);
            }
            else
            {
                root->right = convert(st, ns + 1, ne - 1);
            }
        }
    }
    return root;
}

int main()
{
    // string st = "4(2(3)(1))(6(5))";
    string st= "1(2(3(4))(5(6)(7)))(8(9(1))(2(3)))";
    Node *p = convert(st, 0,  st.size()-1);
    inorderT(p);
    return 0;
}
