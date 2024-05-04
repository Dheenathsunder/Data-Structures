#include <stdio.h>
#include <stdlib.h>
#define max 100

struct stack {
    int arr[max];
    int top;
};

void initialize(struct stack* st) {
    st->top = -1;
}

void push(struct stack* st, int data) {
    if (st->top == max - 1)//isfull function
        printf("Stack is full\n");
    else {
        st->arr[++st->top] = data;
        printf("%d pushed onto the stack\n", data);
    }
}

int pop(struct stack* st) {
    if (st->top == -1)//isempty function
     {
        printf("Stack is empty\n");
        return -1; // Assuming -1 is not a valid value in the stack
    } else {
        int data = st->arr[st->top--];
        return data;
    }
}

void display(struct stack* st) {
    if (st->top == -1)
        printf("Stack is empty\n");
    else {
        printf("Stack elements: ");
        for (int i = 0; i <= st->top; i++) {
            printf("%d ", st->arr[i]);
        }
        printf("\n");
    }
}

int main() {
    struct stack myStack;
    initialize(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    display(&myStack);
    int poppedValue = pop(&myStack);
    if (poppedValue != -1)
        printf("Popped value: %d\n", poppedValue);

    display(&myStack);

    return 0;
}
