#include <stdio.h>
#include <stdlib.h>
#define maxi 100

struct Queue {
    int queue[maxi];
    int size;
    int front;
    int rear;
};

// Initialize Queue
void initQueue(struct Queue *q, int size){
    q->size = size;
    q->front = -1;
    q->rear = -1;
}

// Check if queue is empty
int isEmpty(struct Queue *q){
    return q->front == -1;
}

// Check if queue is full (for circular queue)
int isFull(struct Queue *q){
    return (q->rear + 1) % q->size == q->front;
}

// Push an element into the queue
void push(struct Queue *q, int element){
    if (isFull(q)){
        printf("Queue overflow.\n");
        return;
    }
    if (q->front == -1){  // If inserting first element
        q->front = 0;
    }
    q->rear = (q->rear + 1) % q->size; // Circular increment
    q->queue[q->rear] = element;
    printf("%d pushed into queue.\n", element);
}

// Peek at the front element
int peek(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty.\n");
        return -1;
    }
    return q->queue[q->front]; 
}

// Pop an element from the queue
int pop(struct Queue *q){
    if (isEmpty(q)){
        printf("Queue underflow.\n");
        return -1;
    }
    int popped = q->queue[q->front];
    if (q->front == q->rear){  // If last element is removed, reset queue
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size; // Circular increment
    }
    printf("%d popped from queue.\n", popped);
    return popped;
}

// Print queue elements
void printQueue(struct Queue *q) {
    if (isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->queue[i]);
        if (i == q->rear) break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

// Main function
int main(){
    printf("Enter the size for queue (max %d): ", maxi);
    int size;
    scanf("%d", &size);
    if (size > maxi) {
        printf("Size too large! Max size allowed is %d.\n", maxi);
        return 1;
    }
    
    struct Queue q;
    initQueue(&q, size);

    int choice, element;
    do {
        printf("\nOperations available:\n");
        printf("1. Push\n2. Peek\n3. Pop\n4. Print Queue\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &element);
                push(&q, element);
                break;
            case 2:
                element = peek(&q);
                if (element != -1)
                    printf("Front element: %d\n", element);
                break;
            case 3:
                pop(&q);
                break;
            case 4:
                printQueue(&q);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while(choice != 5);

    return 0;
}
