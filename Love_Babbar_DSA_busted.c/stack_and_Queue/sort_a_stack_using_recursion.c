#include <stdio.h>
#include <stdlib.h>

// Question: Sort a stack using recursion 
struct stack
{
    int top;
    int size;
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
        // printf("%d ", val);
    }
}

int pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        return INT_MAX;
    }
    else
    {
        int val = sp->arr[sp->top];
        sp->top--;
        return val;
    }
}

void push_at_bottom(struct stack *sp, int val)
{
    if (isEmpty(sp))
    {
        sp->top++;
        sp->arr[0] = val;
        return;
    }
    int a = pop(sp);
    push_at_bottom(sp, val);
    push(sp, a);
}

void sorted_push(struct stack *sp, int val)
{

    if (isEmpty(sp) || val < sp->arr[sp->top])
    {
        push(sp, val);
        return;
    }
    int a = pop(sp);
    sorted_push(sp, val);
    push(sp, a);
}
// This is the best approach for the problem for sorting the stack 
// approach: 
// pop all the elements recursively without using the extra space 
// then push the element in the stack back with a sorted_push function see the above code for it's implementation 
// Time complexity: O(N^N)
// space cpmplexity: O(1)
void sort_a_stack(struct stack *sp)
{
    if (isEmpty(sp))
    {
        return;
    }
    int a = pop(sp);
    sort_a_stack(sp);
    sorted_push(sp, a);
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 9;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp, 5);
    push(sp, 2);
    push(sp, 3);
    push(sp, 4);
    sort_a_stack(sp);
    // reverse(sp);
    // reverse_using_recursion(sp);

    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));

    return 0;
}