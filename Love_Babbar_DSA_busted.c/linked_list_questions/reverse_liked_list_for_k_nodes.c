#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *linkedListTraversal(struct Node *head)
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

struct Node *reverseKNodes(struct Node *head, int k)
{
    struct Node *prevptr = NULL;
    struct Node *currptr = head;
    struct Node *nextptr;
    int i = 0;
    while (i != k && currptr != NULL)
    {
        nextptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nextptr;
        i++;
    }

    if (nextptr != NULL)
    {
        head->next = reverseKNodes(nextptr, k);
    }
    return prevptr;
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    printf("Before Reversing\n");
    linkedListTraversal(head);

    // head = reverseLinkedList(head);

    head=reverseKNodes(head, 3);
    printf("\nAfter Reversing\n");
    linkedListTraversal(head);

    return 0;
}