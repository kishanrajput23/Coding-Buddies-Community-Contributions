#include <iostream>
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

int intersection_point_for_two_linked_list(struct Node *head1, struct Node *head2)
{
    struct Node *first = head1;
    struct Node *second = head2;
    int count1 = 0;
    int count2 = 0;
    int a = 0;
    while (first != NULL)
    {
        count1++;
        first = first->next;
    }
    while (second != NULL)
    {
        second = second->next;
        count2++;
    }

    if (count1 > count2)
    {
        a = count1 - count2;
        first = head1;
        second = head2;
    }
    else
    {
        a = count2 - count1;
        first = head2;
        second = head1;
    }
    while (a)
    {
        first = first->next;
        if (first == NULL)
        {
            return -1;
        }
        a--;
    }
    while (first != NULL && second != NULL)
    {
        if (first == second)
        {
            return first->data;
        }

        first = first->next;
        second = second->next;
    }
    return -1;
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

    Node *head2 = new Node;
    Node *second2 = new Node;
    Node *third2 = new Node;
    Node *fourth2 = new Node;
    Node *fifth2 = new Node;
    Node *sixth2 = new Node;

    head2->data = 9;
    head2->next = second2;

    second2->data = 10;
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
    int a = intersection_point_for_two_linked_list(head1, head2);
    printf("%d", a);
    return 0;
}