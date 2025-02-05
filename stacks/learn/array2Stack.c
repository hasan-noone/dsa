#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* st;
    int capacity;
    int top;
} Stack;

// Function prototypes
void initStack(Stack* s, int size);
void push(Stack* s, int x);
int pop(Stack* s);
int peek(Stack* s);
int isFull(Stack* s);
int isEmpty(Stack* s);
void displayStack(Stack* s);
void freeStack(Stack* s);

void initStack(Stack* s, int size) {
    s->st = (int*)malloc(size * sizeof(int));
    if (s->st == NULL) {
        printf("Memory Allocation failed.\n");
        exit(1);
    }
    s->top = -1;
    s->capacity = size;
}

void push(Stack* s, int x) {
    if (isFull(s)) {
        printf("Stack overflow error. Cannot push %d.\n", x);
        return;
    }
    s->st[++(s->top)] = x;
    printf("Pushed: %d\n", x);
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow. Cannot pop from an empty stack.\n");
        return -1;
    }
    return s->st[(s->top)--];
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    return s->st[s->top];
}

int isFull(Stack* s) {
    return s->top == s->capacity - 1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void displayStack(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack contents: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->st[i]);
    }
    printf("\n");
}

void freeStack(Stack* s) {
    free(s->st);
    s->st = NULL;
    s->top = -1;
    s->capacity = 0;
}

int main() {
    Stack s;
    int stackSize = 5;

    // Test 1: Initialize stack
    printf("Initializing stack of size %d\n", stackSize);
    initStack(&s, stackSize);

    // Test 2: Check empty stack
    printf("\nTesting empty stack:\n");
    if(isEmpty(&s)) printf("Stack is empty\n");

    // Test 3: Push elements
    printf("\nPushing elements: 10, 20, 30, 40, 50\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    displayStack(&s);

    // Test 4: Try pushing to full stack
    printf("\nTrying to push to full stack:\n");
    push(&s, 60);

    // Test 5: Check top element
    printf("\nTop element: %d\n", peek(&s));

    // Test 6: Pop elements
    printf("\nPopping three elements:\n");
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));
    displayStack(&s);

    // Test 7: Pop until empty
    printf("\nPopping remaining elements:\n");
    while(!isEmpty(&s)) {
        printf("Popped: %d\n", pop(&s));
    }

    // Test 8: Try to pop from empty stack
    printf("\nTrying to pop from empty stack:\n");
    pop(&s);

    // Clean up
    freeStack(&s);
    return 0;
}
