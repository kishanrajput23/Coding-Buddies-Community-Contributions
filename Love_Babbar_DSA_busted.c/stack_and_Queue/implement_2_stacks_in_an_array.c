#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int size;
    int top1;
    int top2;
    int *arr;
};

int isEmpty1(struct stack *sp)
{
    if (sp->top1 == -1)
    {
        return 1;
    }
    return 0;
}

int isEmpty2(struct stack *sp)
{
    if (sp->top2 == sp->size)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack *sp)
{
    if ((sp->top2 - sp->top1)== 1)
    {
        return 1;
    }
    return 0;
}

void push1(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sp->top1++;
        sp->arr[sp->top1] = val;
        printf("The pushed element in the stack is %d\n", val);
    }
}

void push2(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sp->top2--;
        sp->arr[sp->top2] = val;
        printf("The pushed element in the stack is %d\n", val);
    }
}

int pop1(struct stack *sp)
{
    if (isEmpty1(sp))
    {
        return INT_MAX;
    }
    else
    {
        int val = sp->arr[sp->top1];
        sp->top1--;
        return val;
    }
}

int pop2(struct stack *sp)
{
    if (isEmpty2(sp))
    {
        return INT_MAX;
    }
    else
    {
        int val = sp->arr[sp->top2];
        sp->top2++;
        return val;
    }
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top1 = -1;
    sp->top2 = sp->size;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push1(sp, 1);
    push1(sp, 2);
    push1(sp, 3);
    printf("The popped element from the stack  is %d\n", pop1(sp));
    printf("The popped element from the stack  is %d\n", pop1(sp));
    printf("The popped element from the stack  is %d\n", pop1(sp));
    printf("The popped element from the stack  is %d\n", pop1(sp));
    push2(sp, 5);
    push2(sp, 11);
    // push1(sp, 4);
    printf("The popped element from the stack  is %d\n", pop2(sp));
    // push1(sp, 1);
    // push1(sp, 1);
    return 0;
}