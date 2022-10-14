#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

struct Node *reverseLinkedList(struct Node *head)
{
    struct Node *prevptr = NULL;
    struct Node *currptr = head;
    struct Node *nextptr = NULL;

    while (currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
    }
    head = prevptr;
    return head;
}

// This code is written by me and it's absolutely correct and the Time Complexity: O(n) and space complexity: O(1)

struct Node *add_one(struct Node *head)
{
    // struct Node* p=head;
    struct Node *q = head;
    struct Node *r = (struct Node *)malloc(sizeof(struct Node));
    r->data = 0;
    r->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    if (q->data == 9)
    {
        head = reverseLinkedList(head);
        struct Node *p = head;
        while (p->data == 9)
        {
            p->data = 0;
            if (p->next == NULL)
            {
                p->next = r;
            }
            p = p->next;
        }
        p->data = p->data + 1;
        head = reverseLinkedList(head);
    }
    else
    {
        q->data = q->data + 1;
    }
    return head;
}

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;

    head->data = 9;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 9;
    fourth->next = fifth;

    fifth->data = 9;
    fifth->next = sixth;

    sixth->data = 9;
    sixth->next = NULL;

    printList(head);
    head = add_one(head);
    printList(head);

    return 0;
}