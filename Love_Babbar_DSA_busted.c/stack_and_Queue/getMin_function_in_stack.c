#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Question: Design a data- structure specialStack that supports all the stack operations like push(), pop(), isEmpty(), isFull() and an additional operation getMin() which should return minimum element froom the specialStack. Your task is to complete all the functions, using stack data-structure. 

// Algorithm: push the element in the stack (2*curr- min) and pop from the stack with min= (2*min- curr)
// check on you tube 
// pseudo code

// push
// if(isEmpty()){
//     push(curr);
//        min = curr;
// }
//    else if(curr>= min){
//        push(curr);
//    }
//    else{
//        push(2*curr- min);
//        min = curr;
//    }

// pop
// if(isEmpty(){
//     stack underflow
// })
// else if(curr>= min){
//     pop(curr);
// }
// else{
//     min = 2*min- curr;
//     pop(curr);
// }


struct stack
{
    int size;
    int top;
    int min;
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
    if (sp->top == sp->size - 1)
    {
        return 1;
    }
    return 0;
}

void pop(struct stack *sp)
{
    int curr = sp->arr[sp->top];
    if (isEmpty(sp))
    {
        printf("Stack Underflow\n");
    }
    else if(curr >= sp->min)
    {
        sp->top--;   
    }
    else{
        sp->min = ((2*sp->min)- curr);
        sp->top--;
    }
}

void push(struct stack *sp, int curr)
{
    if (isEmpty(sp))
    {
        sp->top++;
        sp->arr[sp->top] = curr;
        sp->min = curr;
    }
    else if (curr >= sp->min)
    {
        sp->top++;
        sp->arr[sp->top] = curr;
    }
    else{
        int val = ((2*curr) - sp->min);
        sp->top++;
        sp->arr[sp->top] = val;
        sp->min = curr;
    }
}

int getMn(struct stack *sp)
{
    return sp->min;
}

int main()
{
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 4;
    sp->top = -1;
    sp->min = -1;
    sp->arr = (int *)malloc(sp->size * sizeof(int));
    push(sp, 8);
    push(sp, 10);
    push(sp, 6);
    push(sp, 3);
    push(sp, 7);
    pop(sp);
    pop(sp);
    pop(sp);
    int minimum = getMn(sp);
    printf("%d\n", minimum);
    return 0;
}