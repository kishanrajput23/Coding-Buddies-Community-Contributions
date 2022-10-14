#include <iostream>
#include <unordered_map>
using namespace std;
// Rotate a DLL by N Nodes 
// Given a DLL, rotate the linked list counter-clockwise by N nodes. Here N is a given positive intever and is samller than the count of nodes in linked list .
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

void doublyLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    cout << "NULL"
         << "<->";
    while (ptr != NULL)
    {
        cout << ptr->data << "<->";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

struct Node *reverseDoublyLinkedList(struct Node *head)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

// This is the most efficient algorithm for rotating a DLL with given value by N Nodes and it is written by me
// By four pointers p, q, r
//Time complexity: O(N)
//space complexity: O(1)
struct Node *rotate_doubly_linked_list_by_N_nodes(struct Node *head, int N)
{
    struct Node *p = head;
    struct Node *q = head;
    struct Node *r = head->next;
    struct Node *s = head->next;

    for (int i = 0; i < N - 1; i++)
    {
        r = r->next;
        s = s->next;
        q = q->next;
    }

    q->next = NULL;
    q=r;
    r->prev = NULL;

    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
    p->prev = q;
    head = r;

    return head;
}

// By four pointers p, q, r, s
//Time complexity: O(N)
//space complexity: O(1)
//Explanation: Traverse thorough the DLL for the value of N by two pointers and then break the DLL into two parts and then join the first half of  the DLL to the last of the remaining linked list . 
// break the DLL in first half and the second half then make first half as the second half and the second half as the first half of the DLL. and then update the head of the DLL.
// struct Node *rotate_doubly_linked_list_by_N_nodes(struct Node *head, int N)
// {
//     struct Node *p = head;
//     struct Node *q = head;
//     struct Node *r = head->next;
//     struct Node *s = head->next;

//     for (int i = 0; i < N - 1; i++)
//     {
//         r = r->next;
//         s = s->next;
//         q = q->next;
//     }

//     q->next = NULL;
//     r->prev = NULL;

//     while (s->next != NULL)
//     {
//         s = s->next;
//     }
//     s->next = p;
//     p->prev = s;
//     head = r;

//     return head;
// }
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;
    Node *seventh = new Node;

    head->prev = NULL;
    head->data = 1;
    head->next = second;

    second->prev = head;
    second->data = 2;
    second->next = third;

    third->prev = second;
    third->data = 4;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 5;
    fourth->next = fifth;

    fifth->prev = fourth;
    fifth->data = 6;
    fifth->next = sixth;

    sixth->prev = fifth;
    sixth->data = 8;
    sixth->next = seventh;

    seventh->prev = sixth;
    seventh->data = 9;
    seventh->next = NULL;

    doublyLinkedListTraversal(head);
    head = rotate_doubly_linked_list_by_N_nodes(head, 2);
    doublyLinkedListTraversal(head);

    return 0;
}