#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

void circularLinkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    do
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    } while (ptr != head);
    cout << "head" << endl;
}

// Write a function to delete an element of a circular linked list at any given index
// time complexity: O(N)
// space complexity: O(1)
struct Node* delete_an_element_of_circular_list(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    struct Node *r = head;
    int i = 0;
    if (index == 0)
    {
        do
        {
            p = p->next;
        } while (p->next != head);
        // head= head->next;
        p->next = q;
        head=q;
        delete (r);
        return head;
    }
    else
    {

        while (i != index - 1)
        {
            p = p->next;
            q = q->next;
            i++;
        }
        p->next = q->next;
        delete (q);
        return head;
    }
}
int main()
{
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *fourth = new Node;
    Node *fifth = new Node;
    Node *sixth = new Node;

    head->data = 0;
    head->next = second;

    second->data = 1;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = fifth;

    fifth->data = 4;
    fifth->next = sixth;

    sixth->data = 5;
    sixth->next = head;

    circularLinkedListTraversal(head);
    head= delete_an_element_of_circular_list(head, 1);
    circularLinkedListTraversal(head);

    return 0;
}