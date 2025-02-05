#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

// Structure to represent a queue
struct Queue {
    int capacity; // Maximum number of elements in the queue
    int* arr;     // Array to store queue elements
    int front;    // Index of the front element
    int back;     // Index of the last element
};

// Function prototypes
int isEmpty(struct Queue *q);
int isFull(struct Queue *q);
void initQueue(struct Queue *q, int size);
void enqueue(struct Queue *q, int element);
int dequeue(struct Queue *q);
int getSize(struct Queue *q);

// Initialize the queue
void initQueue(struct Queue *q, int size) {
    q->arr = (int*)malloc(size * sizeof(int)); // Allocate memory for queue
    q->capacity = size;
    q->front = -1; // Indicates the queue is empty
    q->back = -1;  // Indicates the queue is empty
}

// Enqueue (add) an element to the queue
void enqueue(struct Queue *q, int element) {
    if (isFull(q)) {
        printf("Queue is full. Cannot enqueue %d.\n", element);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0; // Set front to 0 if queue was empty
    }
    q->back++;
    q->arr[q->back] = element; // Add the new element
}

// Dequeue (remove) an element from the queue
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1; // Return -1 to indicate queue is empty
    }
    int element = q->arr[q->front]; // Get the front element
    q->front++; // Move front index forward
    // Reset queue if it becomes empty
    if (q->front > q->back) {
        q->front = -1;
        q->back = -1;
    }
    return element; // Return the dequeued element
}

// Check if the queue is empty
int isEmpty(struct Queue *q) {
    return (q->front == -1) ? true : false;
}

// Check if the queue is full
int isFull(struct Queue *q) {
    return (q->back == q->capacity - 1) ? true : false;
}

// Get the size of the queue
int getSize(struct Queue *q) {
    if (isEmpty(q)) {
        return 0; // Queue is empty
    }
    return (q->back - q->front + 1); // Calculate size
}

int main() {
    struct Queue q;
    initQueue(&q, 5); // Initialize queue with a capacity of 5

    // Enqueue elements
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("Size of queue: %d\n", getSize(&q));

    // Dequeue an element
    printf("Dequeued element: %d\n", dequeue(&q));
    printf("Size of queue after dequeue: %d\n", getSize(&q));

    // Enqueue more elements
    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60); // This should indicate that the queue is full

    // Dequeue all elements
    while (!isEmpty(&q)) {
        printf("Dequeued element: %d\n", dequeue(&q));
    }

    // Free allocated memory
    free(q.arr);
    return 0;
}
