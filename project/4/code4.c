#include <stdio.h>
#define MaxSize 5
typedef struct
{
    int Q[MaxSize];
    int front;
    int rear;
    int tag;
 }SqQueue;
void InitQueue(SqQueue *q)
 {
    q->front = q->rear = 0;
    q->tag = 0;
 }
int enqueue(SqQueue *q, int x)
 {
    if(q->tag == 1 && q->front == q->rear)
        return 0;
    q->Q[q->rear] = x;
    q->rear = (q->rear + 1) % MaxSize;
    if(q->front == q->rear)
        q->tag = 1;
    return 1;
 }
int dequeue(SqQueue *q, int *x)
 {
    if(q->tag == 0 && q->front == q->rear)
        return 0;
    *x = q->Q[q->front];
    q->front = (q->front + 1) % MaxSize;
    if(q->front == q->rear)
        q->tag = 0;
    return 1;
 }
int main()
 {
    SqQueue q;
    InitQueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    int val;
    dequeue(&q,&val);
    printf("%d",val);
    return 0;
 }