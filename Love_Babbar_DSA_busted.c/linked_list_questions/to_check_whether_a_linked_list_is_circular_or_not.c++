#include <iostream>
using namespace std;
// We need to write a fuction which tells whether a linkekd list is circular or not 
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

// I have done this  problem by modifying floyd's algorithm as when fast and slow pointer will move if there is a loop then fast and slow will be equal once again and also I have created a pointer called head which points to the head1 of the linked list . 
// The main modification is that head == slow== fast if so then it is  a circular linked list 
// Time complexity O(n)
// Space complexity O(1)
int check_whether_a_linked_list_is_circular_or_not(struct Node *head1)
{
    struct Node *head = head1;
    struct Node *slow = head1;
    struct Node *fast = head1;
    if (head == NULL)
    {
        return 1;
    }

    if (head->next == NULL)
    {
        return 0;
    }

    do
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL || slow == NULL)
        {
            break;
        }
    } while (fast != slow);
    if (head == slow)
    {
        return 1;
    }

    return 0;
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

    head1->data = 1;
    head1->next = second1;

    second1->data = 2;
    second1->next = third1;

    third1->data = 3;
    third1->next = fourth1;

    fourth1->data = 4;
    fourth1->next = fifth1;

    fifth1->data = 5;
    fifth1->next = sixth1;

    sixth1->data = 6;
    sixth1->next = NULL;

    int a = check_whether_a_linked_list_is_circular_or_not(head1);
    cout << "The middle element of the linked list is " << a << endl;
    return 0;
}