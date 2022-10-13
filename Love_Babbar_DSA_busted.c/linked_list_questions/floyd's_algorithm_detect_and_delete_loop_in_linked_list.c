#include <stdio.h>
#include <stdlib.h>
#include <mapi.h>
struct Node
{
    int data;
    struct Node *next;
};

// struct Node *linkedListTraversal(struct Node *head)
// {
//     struct Node *ptr = head;
//     while (ptr != NULL)
//     {
//         printf("%d->", ptr->data);
//         ptr = ptr->next;
//     }
//     printf("NULL");
//     printf("\n");
// }

// This algorithm is written by me and the time complexity is: O(n square)
//  and i will  name this algorithm  as racing algorithm
//  int detectLoop(struct Node *head)
//  {
//      struct Node *p = head;
//      struct Node *q = head;
//      while (1)
//      {

//         if (q->next == NULL)
//         {
//             return 0;
//         }

//         if (q->next == p)
//         {
//             return 1;
//         }
//         else
//         {
//             if (p == q)
//             {
//                 q = q->next;
//                 p = head;
//             }
//             else
//             {
//                 p = p->next;
//             }
//         }
//     }
// }

// This delete loop function  is written by me and it's time complexity: O(n square)
// void deleteLoop(struct Node *head)
// {
//     struct Node *p = head;
//     struct Node *q = head;
//     int a = 0;
//     while (1)
//     {

//         if (q->next == p)
//         {
//             a = 1;
//             break;
//         }
//         else
//         {
//             if (p == q)
//             {
//                 q = q->next;
//                 p = head;
//             }
//             else
//             {
//                 p = p->next;
//             }
//         }
//     }
//     if (a == 1)
//     {
//         q->next = NULL;
//     }
// }

// by using mapping we could also solve this problem
// time complexity: O(n)
// space complexity: O(n )
int detect_loop_using_map(struct Node *head)
{
    if (!head)
    {
        return 0;
    }
}

// It's an important question
// To detect a loop in a linked list
// This  algorithm is called as hare and tortoise algorithm (kachua aur rabbit ki kahani)
// Or this algorithm is called as floyd's algorithm
// This is the fastest algorithm to solve this problem
// Time Complexity: O(n)
// space Complexity:O(1)
int detect_Cycle_in_a_linked_list(struct Node *head)
{
    if (head == NULL)
        return 0;
    struct Node *s = head;
    struct Node *f = head;
    int flag = 1;
    do
    {
        if (s == NULL || f == NULL || f->next == NULL)
        {
            flag = 0;
            break;
        }
        s = s->next;
        f = f->next->next;
    } while (s != f);
    return flag;
}

// This is also floyd's algorithm it is the best method to  delete a  cycle in a loop
void removeCycle(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *s = head;
    struct Node *f = head;
    int flag = 1;
    do
    {
        if (s == NULL || f == NULL || f->next == NULL)
        {
            flag = 0;
            break;
        }
        s = s->next;
        f = f->next->next;
    } while (s != f);
    s = head;

    if (flag)
    {
        // this handles the base case when ll is a complete cycle. 
        // e.g. 1->2->3----
        //      ^          |
        //      |  - -  - -
        if (s == head && f == head)
        {
            f = f->next;
            while (f->next != s)
            {
                f = f->next;
            }
            f->next = NULL;
        }
        else
        {
            while (s->next != f->next)
            {
                s = s->next;
                f = f->next;
            }   
            f->next = NULL;
        }
    }
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

    int a = detect_Cycle_in_a_linked_list(head);
    printf("%d\n", a);
    removeCycle(head);
    int b = detect_Cycle_in_a_linked_list(head);
    printf("%d\n", b);
    return 0;
}