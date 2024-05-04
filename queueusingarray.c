#include <stdio.h>
#include <stdlib.h>
#define max 100

struct queue {
    int arr[max];
    int front, rear;
};

void initialize(struct queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isempty(struct queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int isfull(struct queue* q) {
    return (q->rear == max - 1);
}

void insert(struct queue* q, int data) {
    if (isfull(q))
        printf("Queue is full\n");
    else {
        if (isempty(q))
            q->front = q->rear = 0;
        else
            q->rear++;
    }
    q->arr[q->rear] = data;
    printf("%d inserted\n", data);
}

void delete(struct queue* q) {
    if (isempty(q)) {
        printf("Queue is empty\n");
    } else {
        int data = q->arr[q->front];
        if (q->front == q->rear)
            q->front = q->rear = -1;
        else
            q->front++;
        printf("%d deleted from the Queue\n", data);
    }
}

void display(struct queue q) {
    if (isempty(&q))
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = q.front; i <= q.rear; i++)
            printf("%d ", q.arr[i]);
    }
    printf("\n");
}

int main() {
    struct queue myQueue;
    initialize(&myQueue);

    insert(&myQueue, 10);
    insert(&myQueue, 20);
    insert(&myQueue, 30);

    display(myQueue);

    delete(&myQueue);
    display(myQueue);

    return 0;
}
