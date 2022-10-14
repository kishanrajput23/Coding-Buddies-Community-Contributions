#include <stdio.h>
#include <stdlib.h>
// Question: Remove duplicate elements from sorted linked list
// Given a singly linked list consisting of N nodes . The task is to remove duplicates (nodes with duplicate values ) from the given list
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
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
    printf("\n");
}

// struct Node *remove_duplicate_elements_from_sorted_linked_list(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = head;
//     while (q->data != q->next->data)
//     {
//         p = p->next;
//         q = q->next;
//     }
//     while (q->data == q->next->data)
//     {
//         if (q->next==NULL)
//         {
//             break;
//         }

//         q = q->next;
//     }
//     p->next = q->next;
//     return head;
// }

struct Node *remove_duplicate_elements_from_sorted_linked_list(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head;
    while (q->next != NULL)
    {

        if (q->data != q->next->data)
        {
            p = p->next;
            q = q->next;
        }
        else
        {
            q = q->next;
            p->next = q->next;
        }
    }
    return head;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 2;
    third->next = fourth;

    fourth->data = 3;
    fourth->next = fifth;

    fifth->data = 3;
    fifth->next = sixth;

    sixth->data = 4;
    sixth->next = NULL;

    linkedListTraversal(head);
    head = remove_duplicate_elements_from_sorted_linked_list(head);
    linkedListTraversal(head);

    return 0;
}