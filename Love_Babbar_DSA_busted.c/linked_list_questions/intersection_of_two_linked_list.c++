#include <bits/stdc++.h>
using namespace std;
// Write a program to have the intersection of two sorted linked list 
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

// The Time complexity of this function is O(n+m )
struct Node *intersection_of_two_linked_list(struct Node *head1, struct Node *head2)
{
    struct Node* first=head1 ;
    struct Node* second=head2 ;
    struct Node *res = NULL;
    struct Node *temp;
    struct Node *prev = NULL;
    while (first != NULL && second != NULL)
    {
        if (first->data < second->data)
        {
            first = first->next;
        }
        else if (first->data > second->data)
        {
            second =second->next;
        }
        else
        {
            temp = new Node;
            temp->data = first->data;

            if (res == NULL)
            {
                res = temp;
            }
            else
            {
                prev->next = temp;
            }
            prev = temp;
            first = first->next;
            second = second->next;
        }
    }
    temp->next = NULL;
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
    // Node *sixth1 = new Node;

    head1->data = 0;
    head1->next = second1;

    second1->data = 2;
    second1->next = third1;

    third1->data = 4;
    third1->next = fourth1;

    fourth1->data = 5;
    fourth1->next = fifth1;

    fifth1->data = 6;
    fifth1->next = NULL;

    // sixth1->data = 4;
    // sixth1->next = NULL;

    Node *head2 = new Node;
    Node *second2 = new Node;
    Node *third2 = new Node;
    Node *fourth2 = new Node;
    // Node *fifth2 = new Node;
    // Node *sixth2 = new Node;

    head2->data = 0;
    head2->next = second2;

    second2->data = 1;
    second2->next = third2;

    third2->data = 2;
    third2->next = fourth2;

    fourth2->data = 3;
    fourth2->next = NULL;

    // fifth2->data = 3;
    // fifth2->next = sixth2;

    // sixth2->data = 4;
    // sixth2->next = NULL;

    linkedListTraversal(head1);
    linkedListTraversal(head2);
    head = intersection_of_two_linked_list(head1, head2);
    linkedListTraversal(head);

    return 0;
}