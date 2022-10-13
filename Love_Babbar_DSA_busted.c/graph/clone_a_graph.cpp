#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    vector<Node *> neighbours;
    Node(int val)
    {
        data = val;
    }
};

// clone a graph with a given node. 
// kindly check the explanation from tech dose and see the code from code library video 
// this seems to be a easy question of dfs but we need to have patience of doing it as we are getting confused in the old and new references 
// simple dfs 
// time complexity: O(V+E)
// space complexity: O(V+E)
void cloneGraphUtil(Node *node, Node *head, vector<Node *> &vis)
{
    vis[head->data] = head;
    for (auto x : node->neighbours)
    {
        if (!vis[x->data])
        {
            Node *nHead = new Node(x->data);
            (head->neighbours).push_back(nHead);
            cloneGraphUtil(x, nHead, vis);
        }
        else
        {
            (head->neighbours).push_back(vis[x->data]);
        }
    }
}

Node *cloneGraph(Node *node)
{
    if (node == NULL)
        return NULL;

    Node *head = new Node(node->data);
    vector<Node *> vis(1000, NULL);
    cloneGraphUtil(node, head, vis);
    return head;
}

int main()
{
    // Initial graph.
    Node *node = new Node(1);
    Node *node1 = new Node(2);
    Node *node2 = new Node(3);
    Node *node3 = new Node(4);
    (node->neighbours).push_back(node1);
    (node->neighbours).push_back(node3);

    (node1->neighbours).push_back(node);
    (node1->neighbours).push_back(node2);

    (node2->neighbours).push_back(node1);
    (node2->neighbours).push_back(node3);

    (node3->neighbours).push_back(node);
    (node3->neighbours).push_back(node2);

    Node* head = cloneGraph(node);

    
    return 0;
}