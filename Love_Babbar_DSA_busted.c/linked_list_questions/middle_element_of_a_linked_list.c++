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
bool isEven(int size)
{
    if ((size % 2) == 0)
    {
        return true;
    }
    return false;
}
bool isOdd(int size)
{
    if ((size % 2) == 0)
    {
        return false;
    }
    return true;
}

//This is the first approach to find the middle element of a linked list
// In this approach we are using two  loops and the time complexity is O(n)
// int middle_element_of_a_linked_list(struct Node *head1)
// {
//     struct Node *p = head1;
//     int size = 0;
//     while (p != NULL)
//     {
//         size++;
//         p = p->next;
//     }
//     p = head1;
//     if (isEven(size))
//     {
//         size = ((size / 2) + 1);
//         while (size - 1)
//         {
//             p = p->next;
//             size--;
//         }
//     }
//     else
//     {
//         size = ((size + 1) / 2);
//         while (size - 1)
//         {
//             p = p->next;
//             size--;
//         }
//     }
//     return p->data;
// }

// This is second approach and a better as in this we have to use only one loop and time complexity is O(n) so we will use this approach
// space complexity for this approach is O(1)
int middle_element_of_a_linked_list(struct Node *head1)
{
    struct Node *slow = head1;
    struct Node *fast = head1;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == NULL)
        {
            break;
        }
    }
    return slow->data;
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

    linkedListTraversal(head1);
    int a = middle_element_of_a_linked_list(head1);
    cout << "The middle element of the linked list is " << a << endl;
    return 0;
}