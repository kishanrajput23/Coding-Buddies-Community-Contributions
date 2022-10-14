#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct queue{
    int size;
    int f;
    int r;
    int * arr;
};

int isEmpty(struct queue* q){
    if(q->f == q->r){
        return 1;
    }
    return 0;
}

int isFull(struct queue* q){
    if(q->r == (q->size -1)){
        return 1;
    }
    return 0;
}

void enqueue(struct queue* q, int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else{
        q->r++;
        q->arr[q->r]= val;
        printf("You have enqueued element %d\n", val);
    }
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        return INT_MAX;
    }
    else{
        q->f++;
        return q->arr[q->f];
    }
}
int main(){
    struct queue * q = (struct queue*)malloc(sizeof(struct queue));
    q->size = 3;
    q->f = -1;
    q->r = -1;
    q->arr = (int *)malloc(q->size*sizeof(int));
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("The dequeued element is %d\n", dequeue(q));
    printf("The dequeued element is %d\n", dequeue(q));
    printf("The dequeued element is %d\n", dequeue(q));
    printf("The dequeued element is %d\n", dequeue(q));
    // enqueue(q, 4);
    return 0;
}