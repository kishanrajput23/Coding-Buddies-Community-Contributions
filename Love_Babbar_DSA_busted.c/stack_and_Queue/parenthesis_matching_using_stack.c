#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *sp)
{
    if (sp->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct stack* sp){
    if(sp->top == (sp->size-1)){
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


void pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("Stack underflow\n");
    }
    else
    {
        sp->top--;
    }
}

int parenthesisMatching(struct stack *sp, char *arr)
{
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if (arr[i] == '(')
        {
            push(sp, arr[i]);
        }
        if (arr[i] == ')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
    }
    if (isEmpty(sp))
    {
        return 1;
    }
    return 0;
}

int main()
{
    char *arr = "8*2(";
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 8;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    int a = parenthesisMatching(sp, arr);
    if (a == 1)
    {
        printf("parenthesis matching\n");
    }
    else
    {
        printf("parenthesis not matching\n");
    }

    return 0;
}