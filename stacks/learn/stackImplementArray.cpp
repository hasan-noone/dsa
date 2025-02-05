#include <iostream>  // For input-output functionality

class StackImplementation {
    // Variables
   public:
    int top = -1;  // Tracks the top of the stack
    int size;      // Maximum size of the stack
    int* st;       // Dynamic array to store stack elements

    // Constructor to initialize the stack
    StackImplementation(int maxSize) {
        size = maxSize;
        st = new int[size];  // Allocating memory for the stack
    }

    // Destructor to release allocated memory
    ~StackImplementation() {
        delete[] st;
    }

    // Push function
    void push(int n) {
        // Checking for overflow
        if (top >= size - 1) {
            std::cout << "Stack overflow Error\n";
            return;
        }
        top += 1;
        st[top] = n;
    }

    // Peek function
    int peek() {
        // Error exception for empty stack
        if (top == -1) {
            std::cout << "Stack is empty\n";
            return -1;
        }
        return st[top];
    }

    // Pop function
    void pop() {
        if (top == -1) {
            std::cout << "No value is present to pop\n";
            return;
        }
        top -= 1;
    }

    // Size function
    int sizeST() {
        return top + 1;
    }

    //Empty function
    bool isEmpty(){
        return size == 0;
    }
};

int main() {
    StackImplementation stack(5);  // Creating a stack of size 5

    // Example usage
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << "\n";
    stack.pop();
    std::cout << "Top element after pop: " << stack.peek() << "\n";
    std::cout << "Current stack size: " << stack.sizeST() << "\n";

    return 0;
}
