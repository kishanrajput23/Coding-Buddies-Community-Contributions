#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Node *newNode(int data)
{
    Node *ptr = new Node();
    ptr->data = data;
    ptr->next = NULL;
    return ptr;
}

struct myComp
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKSorted(Node *arr[], int k)
{
    priority_queue<Node *, vector<Node *>, myComp> pq;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] != NULL)
        {
            pq.push(arr[i]);
        }
    }

    if (pq.size() == 0)
    {
        return NULL;
    }
    Node *ptr = NULL;
    int f = 0;
    Node *head = NULL;
    while (!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();

        if (f == 0)
        {
            f = 1;
            head = curr;
            ptr = curr;
        }
        else
        {
            ptr->next = curr;
            ptr = curr;
        }

        if (curr->next != NULL)
        {
            pq.push(curr->next);
        }
    }

    return head;
}

void printList(Node *head)
{
    Node *ptr = head;
    while (ptr!= NULL )
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    // k tells the number of linked lists.
    int k = 3;

    Node *arr[k];

    // linked list 1
    arr[0] = newNode(1);
    arr[0]->next = newNode(4);
    arr[0]->next->next = newNode(7);
    arr[0]->next->next->next = newNode(8);

    // linked list 2
    arr[1] = newNode(2);
    arr[1]->next = newNode(12);

    // linked list 3
    arr[2] = newNode(5);
    arr[2]->next = newNode(9);
    arr[2]->next->next = newNode(30);

    Node *head = mergeKSorted(arr, k);

    printList(head);
    return 0;
}