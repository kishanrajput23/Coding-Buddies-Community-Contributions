#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int size;
    int *arr;
};


int isEmpty(struct stack* sp){
    if(sp->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct  stack* sp){
    if(sp->top == (sp->size -1)){
        return 1;
    }
    return 0;
}
int middleElement(struct stack *sp)
{
    if (!isEmpty(sp))
    {
        int r= (sp->top+1);
        int index = (r / 2);
        return sp->arr[index];
    }
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


void push_at_botttom(struct stack *sp, int val)
{
    if (isFull(sp))
    {
        printf("Stack overflow\n");
    }
    else if (isEmpty(sp))
    {
        sp->top++;
        sp->arr[sp->top] = val;
        // printf("%d ", val);
    }
    else
    {
        sp->top++;
        for (int i = sp->top - 1; i >= 0; i--)
        {
            sp->arr[i + 1] = sp->arr[i];
        }
        sp->arr[0] = val;
        // printf("%d ", val);
    }
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
    push_at_botttom(sp, 6);
    push_at_botttom(sp, 7);
    push_at_botttom(sp, 8);
    push_at_botttom(sp, 9);
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    printf("The popped element from the stack is %d \n", pop(sp));
    return 0;
}