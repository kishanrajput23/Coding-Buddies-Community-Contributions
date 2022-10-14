#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void linkedListTraversal(struct Node *head)
{
    struct Node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int isFull(struct Node *head)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (temp == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct Node* head){
    if(head == NULL){
        return 1;
    }
    return 0;
}
void push(struct Node **head, int val)
{
    if (isFull((*head)))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = (*head);
        (*head) = temp;
    }
}

int pop(struct Node **head)
{
    if (isEmpty((*head)))
    {
        return INT_MAX;
    }
    else
    {
        struct Node *temp = (*head);
        int val = temp->data;
        (*head) = (*head)->next;
        free(temp);
        return val;
    }
}

// This can be the most efficient method to reverse a stack
// Implement the stack with the help of the linked list. 
// Time complexity: O(N)
// space complexity: O(1)
void reverse(struct Node* head){
    if(head == NULL){
        return;
    }
    reverse(head->next);
    printf("%d ", head->data);
}
int main()
{
    struct Node *head = NULL;
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    linkedListTraversal(head);
    // pop(&head);
    // pop(&head);
    // linkedListTraversal(head);
    reverse(head);

    return 0;
}