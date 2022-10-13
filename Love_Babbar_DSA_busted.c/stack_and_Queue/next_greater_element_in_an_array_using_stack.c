#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// Question: Find the next greater element in an array using stack. 
// time complexity: O(N)
// space complexity: O(N)

// Approach: push the element of next array into the stack if the top element of the stack is greater than the next array element. pop the element from the stack if the next array element is greater than that of the top element of the stack . pop until next[i]<sp->arr[sp->top] 
// rest see on you tube . for revisinng. 
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

void nextGreater(int next[])
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    for (int i = 0; i < sp->size; i++)
    {
        if (isEmpty(sp))
        {
            push(sp, next[i]);
        }
        else if (sp->arr[sp->top] > next[i])
        {
            push(sp, next[i]);
        }
        else
        {
            while (next[i] > sp->arr[sp->top])
            {
                // if (isEmpty(sp))
                // {
                //     break;
                // }
                printf("%d ---> %d\n", pop(sp), next[i]);
            }
            push(sp, next[i]);
        }
    }
    while (!isEmpty(sp))
    {
        printf("%d ---> -1\n", pop(sp));
    }
}
int main()
{
    int next[] = {2, 1, 4, 3, 5};

    nextGreater(next);
    return 0;
}



