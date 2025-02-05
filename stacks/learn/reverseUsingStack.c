#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define stack structure
#define MAX_SIZE 100

typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Stack operations
void initStack(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}

void push(Stack* s, char c) {
    if (!isFull(s)) {
        s->items[++(s->top)] = c;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->items[(s->top)--];
    }
    return '\0';
}

// String reversal function
void reversed(const char* input, char* output) {
    Stack s;
    initStack(&s);
    
    // Push all characters to stack
    for (int i = 0; input[i] != '\0'; i++) {
        push(&s, input[i]);
    }
    
    // Pop characters to create reversed string
    int i = 0;
    while (!isEmpty(&s)) {
        output[i++] = pop(&s);
    }
    output[i] = '\0';  // Null terminate the string
}

int main() {
    const char* name = "Hasan";
    char rev[MAX_SIZE];
    
    reversed(name, rev);
    printf("%s\n", rev);
    
    return 0;
}
