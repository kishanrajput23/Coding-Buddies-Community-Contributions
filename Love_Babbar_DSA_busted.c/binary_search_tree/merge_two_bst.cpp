#include <bits/stdc++.h>
using namespace std;


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

//time complexity: O(N+M)
// space complexity: O(N+ M)
//see gfg website 
// Method 2 (Merge Inorder Traversals) 
// 1) Do inorder traversal of first tree and store the traversal in one temp array arr1[]. This step takes O(m) time. 
// 2) Do inorder traversal of second tree and store the traversal in another temp array arr2[]. This step takes O(n) time. 
// 3) The arrays created in step 1 and 2 are sorted arrays. Merge the two sorted arrays into one array of size m + n. This step takes O(m+n) time. 
// 4) Construct a balanced tree from the merged array using the technique discussed in this post. This step takes O(m+n) time.
// Time complexity of this method is O(m+n) which is better than method 1. This method takes O(m+n) time even if the input BSTs are not balanced. 
// Following is implementation of this method.
struct Node *createNode(int data)
{
    struct Node *n = new Node();
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorderTraversal(Node *root)
{
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void inorderPush(Node *root, vector<int> &v)
{
    if (!root)
        return;
    inorderPush(root->left, v);
    v.push_back(root->data);
    inorderPush(root->right, v);
}

void sortIt(vector<int> &v1, vector<int> &v2, vector<int> &tvec)
{
    int i = 0;
    int j = 0;
    while (i < v1.size() && j < v2.size())
    {
        if (v1[i] < v2[j])
        {
            tvec.push_back(v1[i]);
            i++;
        }
        else
        {
            tvec.push_back(v2[j]);
            j++;
        }
    }

    while (i < v1.size())
    {
        tvec.push_back(v1[i]);
        i++;
    }

    while (j < v2.size())
    {
        tvec.push_back(v2[j]);
        j++;
    }
}

Node* nbsttobbst( vector<int> &tvec, int low, int high)
{
    if(low>high)
    {
        return NULL;
    }
    int mid = (low+ high)/2;
    Node* root = createNode(tvec[mid]);
    root->left = nbsttobbst(tvec, low, mid-1 );
    root->right = nbsttobbst(tvec, mid+1, high);
    return root;
}


Node* mergeThem(Node* root1, Node* root2)
{
    vector<int> v1;
    vector<int> v2;
    vector<int> tvec;
    inorderPush(root1, v1);
    inorderPush(root2, v2);
    sortIt(v1, v2, tvec);
    Node* root = nbsttobbst(tvec, 0, tvec.size()-1);
    return root;
}


int main()
{
    struct Node *p = createNode(10);
    struct Node *p1 = createNode(5);
    struct Node *p2 = createNode(15);
    struct Node *p3 = createNode(4);
    struct Node *p4 = createNode(6);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct Node *q = createNode(9);
    struct Node *q1 = createNode(1);
    struct Node *q2 = createNode(12);
    struct Node *q3 = createNode(14);


    q->left = q1;
    q->right = q2;
    q2->right = q3;

    Node* root = mergeThem(p, q);
    // cout<<root->data;
    inorderTraversal(root);
    return 0;
}
