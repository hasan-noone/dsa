#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Implementation of a queue using a linked list.
 *
 * This program demonstrates a queue data structure implemented using linked lists.
 * It includes functions for initialization, enqueue, dequeue, and display operations.
 */

/**
 * @struct Node
 * @brief Represents a node in the queue.
 *
 * Each node contains two members:
 * - data: The integer value stored in the node.
 * - next: Pointer to the next node in the queue.
 */
struct Node {
    int data;          /**< Data stored in the node */
    struct Node* next; /**< Pointer to the next node */
};

/**
 * @struct Queue
 * @brief Structure that maintains front and rear pointers.
 *
 * The queue is implemented using a linked list with two pointers:
 * - front: Points to the first element of the queue (for dequeue operations).
 * - rear: Points to the last element of the queue (for enqueue operations).
 */
struct Queue {
    struct Node* front; /**< Pointer to the front node of the queue */
    struct Node* rear;  /**< Pointer to the rear node of the queue */
};

/**
 * @brief Initializes an empty queue.
 *
 * @param q Pointer to the Queue structure to be initialized.
 *
 * Sets both front and rear pointers to NULL, indicating an empty queue.
 * This must be called before using the queue for any operations.
 */
void initQueue(struct Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

/**
 * @brief Checks if the queue is empty.
 *
 * @param q Pointer to the Queue structure to check.
 * @return int Returns 1 (true) if queue is empty, 0 (false) otherwise.
 *
 * A queue is considered empty when its front pointer is NULL.
 * This check should be performed before dequeue operations.
 */
int isEmpty(struct Queue *q) {
    return q->front == NULL;
}

/**
 * @brief Adds a new element to the rear of the queue.
 *
 * @param x Integer value to be added to the queue.
 * @param q Pointer to the Queue structure.
 *
 * This function:
 * 1. Creates a new node with the given value.
 * 2. If the queue is empty, sets both front and rear to the new node.
 * 3. Otherwise, adds the new node at the rear and updates rear pointer.
 *
 * Time Complexity: O(1).
 */
void enqueue(int x, struct Queue *q) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory Allocation failed.\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    
    if (isEmpty(q)) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

/**
 * @brief Removes and returns the element from the front of the queue.
 *
 * @param q Pointer to the Queue structure.
 * @return int The value at the front of the queue, or -1 if queue is empty.
 *
 * This function:
 * 1. Checks if the queue is empty.
 * 2. Stores the front value to return.
 * 3. Updates front pointer to the next node.
 * 4. Frees the removed node.
 * 5. Updates rear pointer to NULL if the queue becomes empty.
 *
 * Time Complexity: O(1).
 */
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int remove = q->front->data;
    struct Node* temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return remove;
}

/**
 * @brief Displays the elements in the queue.
 *
 * @param q Pointer to the Queue structure.
 *
 * Prints the queue elements from front to rear.
 */
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    struct Node* temp = q->front;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

/**
 * @brief Main function for testing the Queue implementation.
 *
 * Example usage:
 * struct Queue q;
 * initQueue(&q);
 * enqueue(10, &q);
 * enqueue(20, &q);
 * int value = dequeue(&q);  // Returns 10.
 *
 * @return int Returns 0 on successful execution.
 */
int main() {
    struct Queue q;
    initQueue(&q);
    
    enqueue(10, &q);
    enqueue(20, &q);
    enqueue(30, &q);
    enqueue(40, &q);
    
    printf("Queue after enqueue operations: ");
    display(&q);
    
    printf("Dequeued: %d\n", dequeue(&q));
    printf("Dequeued: %d\n", dequeue(&q));
    
    printf("Queue after dequeue operations: ");
    display(&q);
    
    return 0;
}
