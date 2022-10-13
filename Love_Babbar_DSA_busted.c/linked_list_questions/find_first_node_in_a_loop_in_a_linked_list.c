#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *find_First_Loop_Node(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == NULL)
        {
            return NULL;
        }

    } while (slow != fast);

    fast = head;
    while (fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    head = slow->next;
    return head;
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
    fourth->next = second;

    head = find_First_Loop_Node(head);
    printf("%d", head->data);

    return 0;
}