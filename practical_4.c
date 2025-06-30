#include <stdio.h>
#include <stdlib.h>

// A linked list node
struct node {
    int data;
    struct node* next;
};

// A stack
struct stack {
    struct node* top;
};

// Stack functions
void push(struct stack* stack, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }
    int data = stack->top->data;
    struct node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int peek(struct stack* stack) {
    if (stack->top == NULL) {
        return -1;
    }
    return stack->top->data;
}

int isEmpty(struct stack* stack) {
    return stack->top == NULL;
}

// Main function
int main() {
    struct stack* stack = (struct stack*)malloc(sizeof(struct stack));
    stack->top = NULL;

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("The top element is %d\n", peek(stack));

    pop(stack);

    printf("The top element is %d\n", peek(stack));

    return 0;
}