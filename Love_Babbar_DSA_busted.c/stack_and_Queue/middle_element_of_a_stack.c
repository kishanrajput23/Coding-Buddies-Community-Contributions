#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct stack
{
    int size;
    int top;
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
    }
}
int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top = -1;
    sp->arr = (int *)malloc(sizeof(int));
    push(sp, 3);
    push(sp, 4);
    push(sp, 6);
    push(sp, 8);
    push(sp, 1);
    printf("The middle element of the stack is %d\n", middleElement(sp));
    return 0;
}