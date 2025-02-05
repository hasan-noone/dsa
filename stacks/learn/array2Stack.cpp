#include <iostream>
#include <vector>
using namespace std;

struct Stack {
    vector<int> st;
    int top;
    int capacity;
};

void initStack(Stack &stack, int size) {
    stack.st.resize(size, 0);
    stack.capacity = size;
    stack.top = -1;
}

bool isFull(Stack &stack){
    return stack.top == stack.capacity - 1;
}

bool isEmpty(Stack &stack){
    return stack.top == -1;
}

void push(int x, Stack &stack){
    if(isFull(stack)){
        cout << "Stack overflow.\n";
        return;
    }
    stack.top += 1;
    stack.st[stack.top] = x;
}

int top(Stack& stack){
    if(isEmpty(stack)){
        cout << "Stack underflow error.\n";
        return -1;
    }
    return stack.st[stack.top];
}

int pop(Stack& stack){
    if(isEmpty(stack)){
        cout << "Stack underflow.\n";
        return -1;
    }
    int popped = stack.st[stack.top];
    stack.top -= 1;
    return popped;
}

// Function to display stack contents
void displayStack(Stack& stack) {
    if(isEmpty(stack)) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack contents: ";
    for(int i = 0; i <= stack.top; i++) {
        cout << stack.st[i] << " ";
    }
    cout << "\n";
}

int main() {
    Stack stack;
    
    // Test 1: Initialize stack
    cout << "Initializing stack of size 5\n";
    initStack(stack, 5);
    
    // Test 2: Check empty stack
    cout << "\nTesting empty stack:\n";
    if(isEmpty(stack)) cout << "Stack is empty\n";
    
    // Test 3: Push elements
    cout << "\nPushing elements: 10, 20, 30, 40, 50\n";
    push(10, stack);
    push(20, stack);
    push(30, stack);
    push(40, stack);
    push(50, stack);
    displayStack(stack);
    
    // Test 4: Try pushing to full stack
    cout << "\nTrying to push to full stack:\n";
    push(60, stack);
    
    // Test 5: Check top element
    cout << "\nTop element: " << top(stack) << endl;
    
    // Test 6: Pop elements
    cout << "\nPopping three elements:\n";
    cout << "Popped: " << pop(stack) << endl;
    cout << "Popped: " << pop(stack) << endl;
    cout << "Popped: " << pop(stack) << endl;
    displayStack(stack);
    
    // Test 7: Check remaining elements
    cout << "\nRemaining elements in stack:\n";
    displayStack(stack);
    
    // Test 8: Pop until empty
    cout << "\nPopping remaining elements:\n";
    while(!isEmpty(stack)) {
        cout << "Popped: " << pop(stack) << endl;
    }
    
    // Test 9: Try to pop from empty stack
    cout << "\nTrying to pop from empty stack:\n";
    pop(stack);
    
    return 0;
}
