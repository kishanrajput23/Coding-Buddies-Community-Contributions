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
    cout << "NULL"<<"<=>";
    while (ptr != NULL)
    {
        cout << ptr->data << "<=>";
        ptr = ptr->next;
    }
    cout << "NULL"<<endl;
}

struct Node *reverseDoublyLinkedList(struct Node *head)
{
    struct Node* ptr1= head;
    struct Node* ptr2 =ptr1->next;

    ptr1->next= NULL;
    ptr1->prev= ptr2;

    while(ptr2 != NULL){
        ptr2->prev= ptr2->next;
        ptr2->next= ptr1;
        ptr1=ptr2;
        ptr2= ptr2->prev;
    }
    head=ptr1;
    return head;

}

int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;

    head->prev = NULL;
    head->data = 7;
    head->next = second;

    second->prev = head;
    second->data = 11;
    second->next = third;

    third->prev = second;
    third->data = 41;
    third->next = fourth;

    fourth->prev = third;
    fourth->data = 66;
    fourth->next = NULL;

    doublyLinkedListTraversal(head);
    head=  reverseDoublyLinkedList(head);
    doublyLinkedListTraversal(head);
    return 0;
}