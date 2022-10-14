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
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// This is an important question for the interview how to  reverse a linked list
// We have two approaches to reverse a linnked list 1. Iterative approach  , 2. recursive approach
// Time Complexity: O(n )
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

// by method of recursion
void reverseLinkedListByRecursion(struct Node* ptr){
    if(ptr==NULL){
        return;
    }

    reverseLinkedListByRecursion(ptr->next);
    printf("Element: %d\n", ptr->data);
}
int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));


    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 41;
    third->next = fourth;

    fourth->data = 66;
    fourth->next = NULL;

    printf("Before Reversing\n");
    linkedListTraversal(head);

    // head = reverseLinkedList(head);

    printf("After Reversing\n");
    // linkedListTraversal(head);

    reverseLinkedListByRecursion(head);
    return 0;
}