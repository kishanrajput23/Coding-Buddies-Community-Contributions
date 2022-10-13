#include <iostream>
using namespace std;
// Question: Write a function to check whether a given linked list is a palindrome or not 
// e.g. : 1->2->2->1->NULL : This linked list is a palindrome as it looks exactly same as from starting and end 
// 1->2->3->4->NULL : This linked list is not a palindrome as it does not look same from starting and ending 

struct Node
{
    int data;
    struct Node *next;
};

bool isEven(int count)
{
    if ((count % 2) == 0)
    {
        return true;
    }
    return false;
}

bool isOdd(int count)
{
    if ((count % 2) != 0)
    {
        return true;
    }
    return false;
}

struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next;
    return head;
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

// This function is written by me and the time complexity : O(N)
// space complexity: O(1)
// But there is a better approach than this and that is also written by me

// bool palindrome_linked_list_or_not(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = head;
//     struct Node *r;
//     int count = 0;
//     do
//     {
//         p = p->next;
//         count++;
//     } while (p != NULL);
//     p = head;
//     if (isOdd(count))
//     {
//         count = (count / 2);
//         head = deleteAtIndex(head, count);
//         while (count - 1)
//         {
//             p = p->next;
//             count--;
//         }

//         q = p->next;
//         p->next = NULL;
//         r = reverseLinkedList(q);
//         p->next = r;
//         p = head;
//         while (r != NULL)
//         {
//             if (p->data != r->data)
//             {
//                 return false;
//             }
//             p = p->next;
//             r = r->next;
//         }
//     }

//     if (isEven(count))
//     {
//         count = (count / 2);
//         while (count - 1)
//         {
//             p = p->next;
//             count--;
//         }

//         q = p->next;
//         p->next = NULL;
//         r = reverseLinkedList(q);
//         p->next = r;
//         p = head;
//         while (r != NULL)
//         {
//             if (p->data != r->data)
//             {
//                 return false;
//             }
//             p = p->next;
//             r = r->next;
//         }
//     }
//     return true;
// }

// This is a better approach and is also written by me
// 1. First calculate the size of the linked list 
// 2. Then divide that linked list from between 
// 3. Then check whether the two linked lists are identical 
// 4. If so then return true otherwise return false.
// Time complexity: O(N)
// Space complexity: O(1)
bool palindrome_check(struct Node *head)
{
    int count = 0;
    struct Node *p = head;
    struct Node *q;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    p = head;
    count = (count / 2);
    while (count - 1)
    {
        p = p->next;
        count--;
    }
    q = p->next;
    p->next = NULL;
    p = head;
    q = reverseLinkedList(q);

    while (p != NULL && q != NULL)
    {
        if (p->data != q->data)
        {
            return false;
        }
        p = p->next;
        q = q->next;
    }
    return true;
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

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = fifth;

    fifth->data = 3;
    fifth->next = sixth;

    sixth->data = 2;
    sixth->next = seventh;

    seventh->data = 1;
    seventh->next = NULL;

    cout << palindrome_check(head);

    return 0;
}