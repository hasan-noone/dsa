#include <iostream>

class QueueImplementation {
   private:  // Better encapsulation by making variables private
    int size;
    int front;
    int rear;
    int *q;

   public:
    // Constructor with member initializer list
    QueueImplementation(int maxSize) : size(maxSize), front(-1), rear(-1) {
        if (maxSize <= 0) {
            throw std::invalid_argument("Queue size must be positive");
        }
        q = new int[size];
    }

    // Destructor - already good
    ~QueueImplementation() { delete[] q; }

    // Push (Enqueue)
    void push(int x) {
        if (rear >= size - 1) {
            std::cout << "Queue Overflow\n";
            return;
        }
        if (isEmpty()) {  // More intuitive than checking front == -1
            front = 0;
            rear = 0;
        } else {
            rear++;
        }
        q[rear] = x;
    }

    // Pop (Dequeue)
    void pop() {
        if (isEmpty()) {
            std::cout << "Queue Underflow\n";
            return;
        }
        // Shift all remaining elements to the left
        for (int i = front; i < rear; i++) {
            q[i] = q[i + 1];
        }
        if (front == rear) {  // Last element being removed
            front = -1;
            rear = -1;
        } else {
            rear--;
        }
    }

    // Peek with const qualifier
    int peek() const {
        if (isEmpty()) {
            std::cout << "Queue is empty\n";
            return -1;
        }
        return q[front];
    }

    // Get size with const qualifier
    int sizeQ() const {
        if (isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }

    // Check if empty with const qualifier
    bool isEmpty() const {
        return front == -1;  // Simplified condition
    }

    // Added clear method for convenience
    void clear() {
        front = -1;
        rear = -1;
    }
};

int main() {
    try {
        QueueImplementation queue(5);

        // Test the queue operations
        queue.push(10);
        queue.push(20);
        queue.push(30);
        std::cout << "Front element: " << queue.peek() << "\n";
        std::cout << "Queue size: " << queue.sizeQ() << "\n";

        queue.pop();
        std::cout << "Front element after pop: " << queue.peek() << "\n";
        std::cout << "Queue size: " << queue.sizeQ() << "\n";

        queue.pop();
        queue.pop();
        queue.pop();  // Should print Underflow

        // Test overflow
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        queue.push(5);
        queue.push(6);  // Should print Overflow

    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
