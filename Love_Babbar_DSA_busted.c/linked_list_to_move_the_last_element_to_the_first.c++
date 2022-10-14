#include <bits/stdc++.h>
using namespace std;
// Question:- Move last element to first of a given linked list 
// Write a function that moves the last element to the front in a given singly linked list. For example, if the given Linked List is 1->2->3 , then the function should the change the list to 3->2->1


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

// This  function is written by me and not seen from anywhere and the 
// Time Complexity: O(N)
// Space Complexity: O(1)
struct Node *Move_last_element_to_first(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    q->next = head;
    head = q;
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

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 5;
    fifth->next = sixth;

    sixth->data = 6;
    sixth->next = NULL;

    linkedListTraversal(head);
    head=Move_last_element_to_first(head);
    linkedListTraversal(head);
    return 0;
}