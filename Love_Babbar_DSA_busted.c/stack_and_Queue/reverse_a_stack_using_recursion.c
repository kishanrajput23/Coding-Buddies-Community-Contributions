#include <stdio.h>
#include <stdlib.h>

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

// This is reversing the stack without recursion
// space complexity: O(N)
//  time complexity: O(N)
void reverse(struct stack *sp)
{
    int *temp = (int *)malloc(sp->size * sizeof(int));
    int i = 0;
    while (!isEmpty(sp))
    {
        temp[i] = pop(sp);
        i++;
    }

    for (int j = 0; j < i; j++)
    {
        push(sp, temp[j]);
    }
}


// This is the approach by which we could reverse a stack, using recursion
// pop all the elements from the stack
// then use push_at_bottom function 
// hence our stack would be reversed. 
// time complexity: O(N^N)
// space complexity: O(1)
void reverse_using_recursion(struct stack* sp){
    if(isEmpty(sp)){
        return;
    }
    int a = pop(sp);
    reverse_using_recursion(sp);
    push_at_bottom(sp, a);
}


int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 9;
    sp->top = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp, 5);
    push(sp, 4);
    push(sp, 3);
    push(sp, 2);
    // reverse(sp);
    reverse_using_recursion(sp);

    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));

    return 0;
}