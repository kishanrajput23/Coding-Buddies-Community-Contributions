#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
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

struct Node *add_two_linked_lists(struct Node *head1, struct Node *head2)
{
    head1 = reverseLinkedList(head1);
    head2 = reverseLinkedList(head2);
    int s = 0;
    int c = 0;
    struct Node *temp;
    struct Node *res = NULL;
    struct Node *prev = NULL;

    while (head1 != NULL || head2 != NULL)
    {
        s = c + (head1 ? head1->data : 0) + (head2 ? head2->data : 0);
        c = ((s >= 10) ? 1 : 0);
        s = s % 10;
        temp = new Node;
        temp->data = s;

        if (res == NULL)
        {
            res = temp;
        }
        else
        {
            prev->next = temp;
        }
        prev = temp;

        if (head1)
        {
            head1 = head1->next;
        }
        if (head2)
        {
            head2 = head2->next;
        }
    }
    if (c)
    {
        Node *one = new Node;
        one->data = 1;
        temp->next = one;
        one->next = NULL;
    }
    else
    {

        temp->next = NULL;
    }
    res = reverseLinkedList(res);
    return res;
}
int main()
{
    Node *head = new Node;
    Node *head1 = new Node;
    Node *second1 = new Node;
    Node *third1 = new Node;
    Node *fourth1 = new Node;
    Node *fifth1 = new Node;
    Node *sixth1 = new Node;

    head1->data = 9;
    head1->next = second1;

    second1->data = 8;
    second1->next = NULL;

    // third1->data = 5;
    // third1->next = NULL;

    // fourth1->data = 3;
    // fourth1->next = fifth1;

    // fifth1->data = 3;
    // fifth1->next = sixth1;

    // sixth1->data = 4;
    // sixth1->next = NULL;

    Node *head2 = new Node;
    Node *second2 = new Node;
    Node *third2 = new Node;
    Node *fourth2 = new Node;
    Node *fifth2 = new Node;
    Node *sixth2 = new Node;

    head2->data = 2;
    head2->next = NULL;

    // second2->data = 5;
    // second2->next = NULL;

    // third2->data = 2;
    // third2->next = fourth2;

    // fourth2->data = 3;
    // fourth2->next = fifth2;

    // fifth2->data = 3;
    // fifth2->next = sixth2;

    // sixth2->data = 4;
    // sixth2->next = NULL;

    linkedListTraversal(head1);
    linkedListTraversal(head2);
    head = add_two_linked_lists(head1, head2);
    linkedListTraversal(head);

    return 0;
}