#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Given a string, reverse it using stack. For example “GeeksQuiz” should be converted to “ziuQskeeG”.
// Following is simple algorithm to reverse a string using stack. 
 

// 1) Create an empty stack.
// 2) One by one push all characters of string to stack.
// 3) One by one pop all characters from stack and put 
//    them back to string.

// Time complexity: O(1)
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

int isFull(struct stack *sp)
{
    if (sp->top == (sp->size - 1))
    {
        return 1;
    }
    return 0;
}

void push(struct stack *sp, char val)
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

char pop(struct stack *sp)
{
    if (isEmpty(sp))
    {
        printf("stack underflow");
    }
    else
    {
    char val = sp->arr[sp->top];
    sp->top--;
    return val;
    }
}

void reverse_string_using_stack(char string[])
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 5;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    int i = 0;
    for (i = 0; i < sp->size; i++)
    {
        push(sp, string[i]);
    }

    for (i = 0; i < sp->size; i++)
    {
        string[i] = pop(sp);

    }

}

int main()
{
    char string[] = "abcde";
    reverse_string_using_stack(string);
    printf("the reversed string is %s", string );

    return 0;
}