#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>

typedef struct _queue{
    int *A;
    int length;
    int front;
    int rear;
    int size;
} Queue;

Queue* createQueue(int capacity){
    Queue* q= (Queue*)malloc(sizeof(Queue));
    q->A = (int*)malloc(sizeof(int) * capacity);
    q->front = 0;
    q->length = 0;
    q->rear = - 1;
    q->size = capacity;
    return q;
}

bool isEmpty(Queue* q){
    return q->length == 0;
}

bool isFull(Queue* q){
    return q->length == q->size;
}

void enqueue(Queue* q, int item){
    if(isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->A[q->rear] = item;
    q->length++;
    printf("%d enqueued into the queue\n", item);
}

int dequeue(Queue* q){
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    int del = q->A[q->front];
    q->front = (q->front + 1) % q->size;
    q->length--;
    printf("%d dequeued from the queue\n", del);
    return del;
}

int front(Queue* q){
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->A[q->front];
}

int rear(Queue* q){
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    return q->A[q->rear];
}

void display(Queue* q){
    if(isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        int i = q->front;
        for(int j = 0; j < q->length; j++) {
            printf("%d ", q->A[i]);
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
}

int main(){
    Queue* myQueue = createQueue(5);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    display(myQueue);

    printf("Front element: %d\n", front(myQueue));
    printf("Rear element: %d\n", rear(myQueue));

    dequeue(myQueue);
    display(myQueue);

    return 0;
}
