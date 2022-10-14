#include <bits/stdc++.h>
using namespace std;
// Question: Multiply two numbers represented by linked lists.
// Explanation: Given two numbers represented by linked lists, write a funtion that returns the multiplication of these two linked lists.
// e.g. :
// input:  9->4->6
//         8->4
// output: 79464
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

// This is the algorithm.
// This is an important concept to understand . There is a method by which we can convert a string and a linked list to a number .
// The only formula to do this is as : int num =0,  num = num*10 + p->data . tnen after converting them into numbers then we can find their product , addition, subtraction, or any of the other mathematical operation.
// time  complexity: O(N)
// space complexity: O(1)

int multiply_two_linked_lists(struct Node *head1, struct Node *head2)
{
    int num1 = 0;
    int num2 = 0;
    // while (head1 != NULL)
    // {
    //     num1 = (num1 * 10) + head1->data;
    //     head1 = head1->next;
    // }
    // while (head2 != NULL)
    // {
    //     num2 = (num2 * 10) + head2->data;
    //     head2 = head2->next;
    // }

    while (head2 != NULL || head1 != NULL)
    {
        if (head1 != NULL)
        {

            num1 = (num1 * 10) + head1->data;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            num2 = (num2 * 10) + head2->data;
            head2 = head2->next;
        }
    }
    return num1 * num2;
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
    second1->next = third1;

    third1->data = 5;
    third1->next = fourth1;

    fourth1->data = 3;
    fourth1->next = fifth1;

    fifth1->data = 3;
    fifth1->next = sixth1;

    sixth1->data = 4;
    sixth1->next = NULL;

    Node *head2 = new Node;
    Node *second2 = new Node;
    Node *third2 = new Node;
    Node *fourth2 = new Node;
    Node *fifth2 = new Node;
    Node *sixth2 = new Node;

    head2->data = 2;
    head2->next = second2;

    second2->data = 5;
    second2->next = NULL;

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
    int result = multiply_two_linked_lists(head1, head2);
    cout << result;
    // linkedListTraversal(head);

    return 0;
}