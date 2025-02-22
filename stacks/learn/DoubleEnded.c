#include <stdio.h>
#include <stdlib.h>

#define MAXI 100

struct Deque {
    int front;
    int rear;
    int size;
    int q[MAXI];
};

// Initialize the deque
void initDeque(struct Deque *dq, int cap) {
    dq->front = -1;
    dq->rear = -1;
    dq->size = cap;
}

// Check if deque is empty
int isEmpty(struct Deque *dq) {
    return dq->front == -1;
}

// Check if deque is full
int isFull(struct Deque *dq) {
    return (dq->rear + 1) % dq->size == dq->front;
}

// Insert at the front
void pushFront(struct Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Deque is Full.\n");
        return;
    }

    if (isEmpty(dq)) {  // First insertion
        dq->front = dq->rear = 0;
    } else if (dq->front == 0) {
        dq->front = dq->size - 1;  // Circular wrap
    } else {
        dq->front--;
    }

    dq->q[dq->front] = x;
}

// Insert at the back
void pushBack(struct Deque *dq, int x) {
    if (isFull(dq)) {
        printf("Deque is Full.\n");
        return;
    }

    if (isEmpty(dq)) {  // First insertion
        dq->front = dq->rear = 0;
    } else {
        dq->rear = (dq->rear + 1) % dq->size;
    }

    dq->q[dq->rear] = x;
}

// Remove from the front
int popFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty.\n");
        return -1;
    }

    int removed = dq->q[dq->front];

    if (dq->front == dq->rear) {  // Last element removed
        dq->front = dq->rear = -1;
    } else {
        dq->front = (dq->front + 1) % dq->size;
    }

    return removed;
}

// Remove from the back
int popBack(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty.\n");
        return -1;
    }

    int removed = dq->q[dq->rear];

    if (dq->front == dq->rear) {  // Last element removed
        dq->front = dq->rear = -1;
    } else if (dq->rear == 0) {
        dq->rear = dq->size - 1;  // Circular wrap
    } else {
        dq->rear--;
    }

    return removed;
}

// Get the front element
int peekFront(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty.\n");
        return -1;
    }
    return dq->q[dq->front];
}

// Get the back element
int peekBack(struct Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is Empty.\n");
        return -1;
    }
    return dq->q[dq->rear];
}

// Driver function for testing
int main() {
    struct Deque dq;
    initDeque(&dq, MAXI);

    pushFront(&dq, 10);
    pushBack(&dq, 20);
    pushFront(&dq, 5);
    pushBack(&dq, 25);

    printf("Front: %d\n", peekFront(&dq));  // Should print 5
    printf("Back: %d\n", peekBack(&dq));    // Should print 25

    printf("Popped Front: %d\n", popFront(&dq));  // Should remove 5
    printf("Popped Back: %d\n", popBack(&dq));    // Should remove 25

    printf("New Front: %d\n", peekFront(&dq));  // Should print 10
    printf("New Back: %d\n", peekBack(&dq));    // Should print 20

    return 0;
}
