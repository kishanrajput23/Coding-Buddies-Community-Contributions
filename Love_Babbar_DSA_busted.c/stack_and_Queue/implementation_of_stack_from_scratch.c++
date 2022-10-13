#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}


int isFull(struct stack *sp)
{
    if (sp->top == (sp->size - 1))
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        sp->top++;
        sp->arr[sp->top] = val;
        printf("The pushed element is %d \n", val);
    }
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        // Assuming the stack does not contain the negative values.
        return -1;
        printf("stack Underflow\n");
        
    }
    else
    {
        int val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp, 1);
    push(sp, 2);
    push(sp, 3);
    printf("The popped element from the stack is %d\n",pop(sp));
    printf("The popped element from the stack is %d\n",pop(sp));
    printf("The popped element from the stack is %d\n",pop(sp));
    pop(sp);

    return 0;
}