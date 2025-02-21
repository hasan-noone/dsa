#include <stdio.h>
#include <stdlib.h>

/**
 * Structure representing a node in the stack.
 */
typedef struct Node {
    int data;  ///< Data stored in the node
    struct Node* next;  ///< Pointer to the next node in the stack
} Node;

/**
 * Structure representing the stack.
 */
typedef struct Stack {
    Node* top;  ///< Pointer to the top node of the stack
} Stack;

/**
 * Initializes the stack.
 * 
 * @param stack Pointer to the stack structure
 */
void initStack(Stack* stack) {
    stack->top = NULL;
}

/**
 * Checks if the stack is empty.
 *
 * @param stack Pointer to the stack structure
 * @return 1 if stack is empty, otherwise 0
 */
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

/**
 * Pushes an element onto the stack.
 *
 * @param stack Pointer to the stack structure
 * @param value Value to be pushed onto the stack
 */
void push(Stack* stack, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

/**
 * Pops an element from the stack.
 *
 * @param stack Pointer to the stack structure
 * @return Popped value, or -1 if stack is empty
 */
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;  ///< Return an invalid value
    }
    Node* temp = stack->top;
    int poppedValue = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return poppedValue;
}

/**
 * Retrieves the top element of the stack without removing it.
 *
 * @param stack Pointer to the stack structure
 * @return Top element, or -1 if stack is empty
 */
int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;  ///< Return an invalid value
    }
    return stack->top->data;
}

/**
 * Frees the memory allocated for the stack.
 *
 * @param stack Pointer to the stack structure
 */
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
}

/**
 * Main function to test the stack implementation.
 *
 * @return 0 on successful execution
 */
int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element: %d\n", top(&stack));  ///< Should print 30
    printf("Popped: %d\n", pop(&stack));      ///< Should print 30
    printf("Popped: %d\n", pop(&stack));      ///< Should print 20
    printf("Top element: %d\n", top(&stack));  ///< Should print 10

    freeStack(&stack);  ///< Clean up allocated memory
    return 0;
}
