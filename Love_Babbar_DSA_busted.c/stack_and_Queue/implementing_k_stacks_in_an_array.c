#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int *arr;
    int *top;
    int *next;
    int size;
    int k;
    int free;
};

int isFull(struct stack *sp)
{
    if (sp->free == -1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct stack *sp, int sn)
{
    if (sp->top[sn] == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, int sn, int data)
{
    if (isFull(sp))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        int i = sp->free;
        sp->free = sp->next[i];
        sp->next[i] = sp->top[sn];
        sp->top[sn] = i;
        sp->arr[i] = data;
        printf("The pushed element is %d in stack number %d\n", data, sn);
    }
}

int pop(struct stack *sp, int sn)
{
    if (isEmpty(sp, sn))
    {
        printf("Cannot pop element from the stack number %d\n", sn);
        return INT_MAX;
    }
    else
    {
        int i = sp->top[sn];
        sp->top[sn]= sp->next[i];
        sp->next[i] = sp->free;
        sp->free= i;

        return sp->arr[i];
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->k = 3;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    sp->next = (int *)malloc(sp->size * sizeof(int));
    sp->top = (int *)malloc(sp->k * sizeof(int));
    sp->free = 0;
    for (int i = 0; i < sp->size - 1; i++)
    {
        sp->next[i] = (i + 1);
    }
    sp->next[sp->size - 1] = -1;

    for (int i = 0; i < sp->k; i++)
    {
        sp->top[i] = -1;
    }
    // int sn = 1;
    push(sp, 1, 23);
    push(sp, 2, 22);
    push(sp, 0, 10);
    push(sp, 0, 52);
    push(sp, 0, 32);
    // push(sp, 1, 32);

    printf("The popped element is %d from stack number %d\n", pop(sp, 1), 1);
    printf("The popped element is %d from stack number %d\n", pop(sp, 2), 2);
    printf("The popped element is %d from stack number %d\n", pop(sp, 0), 0);
    printf("The popped element is %d from stack number %d\n", pop(sp, 0), 0);
    printf("The popped element is %d from stack number %d\n", pop(sp, 0), 0);
    return 0;
}