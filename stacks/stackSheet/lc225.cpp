#include <iostream>
#include <queue>

class MyStack {
private:
    std::queue<int> q;
    int topElement; // To keep track of the top element

public:
    MyStack() {}

    void push(int x) {
        q.push(x);
        topElement = x; // Update the top element
    }

    int pop() {
        // Rotate the elements except the last one
        int size = q.size();
        for (int i = 0; i < size - 1; i++) {
            topElement = q.front(); // Update topElement to the next element
            q.push(q.front());      // Move front element to the back
            q.pop();                // Remove it from the front
        }
        int popped = q.front(); // This is the last element to be popped
        q.pop();                // Remove the last element
        return popped;          // Return the popped element
    }

    int top() { 
        return topElement; 
    }

    bool empty() { 
        return q.empty(); 
    }
};

int main() {
    MyStack* obj = new MyStack();

    // Push elements onto the stack
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->push(4);
    obj->push(5);

    // Display the top element
    std::cout << "Top element: " << obj->top() << std::endl;

    // Pop elements from the stack
    std::cout << "Popped: " << obj->pop() << std::endl;
    std::cout << "Popped: " << obj->pop() << std::endl;

    // Display the new top element
    std::cout << "Top element after popping: " << obj->top() << std::endl;

    // Check if the stack is empty
    std::cout << "Is the stack empty? " << (obj->empty() ? "Yes" : "No") << std::endl;

    // Clean up
    delete obj;

    return 0;
}
