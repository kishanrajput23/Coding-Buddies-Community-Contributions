#include <iostream>
using namespace std;
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
         << "<=>";
    while (ptr != NULL)
    {
        cout << ptr->data << "<=>";
        ptr = ptr->next;
    }
    cout << "NULL" << endl;
}

struct Node *reverseDoublyLinkedListKNodes(struct Node *head, int k)
{
    struct Node *ptr1 = head;
    struct Node *ptr2 = ptr1->next;
    int i = 0;
    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while (i < k-1 && ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
        i++;
    }

    if (ptr2 != NULL)
    {
        head->next = reverseDoublyLinkedListKNodes(ptr2, k);
    }

    return ptr1;
}

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
    head = reverseDoublyLinkedListKNodes(head, 4);
    doublyLinkedListTraversal(head);
    return 0;
}