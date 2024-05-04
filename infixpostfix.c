#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

char peek(Stack* stack) {
    return stack->items[stack->top];
}

void push(Stack* stack, char item) {
    stack->items[++stack->top] = item;
}

char pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top--];
    }
    return '\0'; // You may want to handle this case differently based on your requirements.
}

int chooseChar(char ch) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
        return 1;
    else if (ch == '(' || ch == ')' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^')
        return 2;
    else
        return 3;
}

int precedence(char ch) {
    switch (ch) {
        case '(': return 1;
        case '+': return 2;
        case '-': return 2;
        case '*': return 3;
        case '/': return 3;
        case '%': return 3;
        case '^': return 4;
        default: return -1;
    }
}

void infixToPostfix(char infix[], int n) {
    char postfix[n + 1];
    Stack* st = createStack();
    int k = 0; // pointing to the index of postfix exp.
    
    for (int i = 0; i < n; i++) {
        int type = chooseChar(infix[i]);
        if (type == 1) {
            postfix[k++] = infix[i];
        } else if (type == 2) {
            if (infix[i] == '(')
                push(st, infix[i]);
            else if (infix[i] == ')') {
                while (peek(st) != '(') {
                    postfix[k++] = pop(st);
                }
                pop(st); // Pop '('
            } else {
                while (!isEmpty(st) && precedence(infix[i]) <= precedence(peek(st))) {
                    postfix[k++] = pop(st);
                }
                push(st, infix[i]);
            }
        }
    }

    while (!isEmpty(st))
        postfix[k++] = pop(st);

    postfix[k] = '\0';

    printf("%s", postfix);
}

int main() {
    char infix[100];
    scanf("%s", infix);
    int len = strlen(infix);
    infixToPostfix(infix, len);

    return 0;
}
