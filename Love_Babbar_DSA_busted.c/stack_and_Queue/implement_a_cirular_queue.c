#include<stdio.h>
#include<stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isEmpty(struct circularQueue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

int isFull(struct circularQueue *q)
{
   ((q->r + 1) % q->size);
    if (((q->r + 1) % q->size)== q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct circularQueue *q, int val)
{
    if (isFull(q))
    {
        printf("Circular Queue Overflow\n");
    }
    else
    {
        q->r = ((q->r + 1) % q->size);
        q->arr[q->r] = val;
    }
}

int dequeue(struct circularQueue *q)
{
    if (isEmpty(q))
    {
        printf("circular Queue underflow\n");
        return -1;
    }
    else
    {
        q->f = ((q->f + 1) % q->size);
        return q->arr[q->f];
    }
}
int main()
{
    struct circularQueue *q = (struct circularQueue *)malloc(sizeof(struct circularQueue));
    q->size = 4;
    q->f = 0;
    q->r = 0;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    printf("%d\n", dequeue(q));
    return 0;
}