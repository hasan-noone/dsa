#include <iostream>
#include <stack>
#include <string>
#include <vector>

// Custom search function
bool doesContains(const std::stack<std::string>& st, const std::string& target) {
    // Create a copy of the stack for traversal
    std::stack<std::string> temp = st;
    while (!temp.empty()) {
        if (temp.top() == target) {
            return true;
        }
        temp.pop();
    }
    return false;
}

// Custom peek function
std::string myPeek(const std::stack<std::string>& st) {
    if (!st.empty()) {
        return st.top();
    } else {
        return "Stack is empty!";
    }
}

// Function to print stack without modifying it
void displayStack(const std::stack<std::string>& st) {
    // Create a copy of the stack for traversal
    std::stack<std::string> temp = st;
    // Store elements in a vector to print in original order
    std::vector<std::string> elements;
    
    while (temp.empty() != true) {
        elements.push_back(temp.top());
        temp.pop();
    }
    
    std::cout << "Stack elements (from top to bottom): ";
    for (int i = elements.size() - 1; i >= 0; --i) {
        std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::stack<std::string> st;
    
    // Pushing elements
    st.push("Minecraft");
    st.push("Minecraft");
    st.push("FFVII");
    st.push("Skydoom");
    st.push("Skyrim");
    // Display top element
    std::cout << "Top element: " << myPeek(st) << std::endl;
    
    // Display full stack
    displayStack(st);
    
    // Verify stack is unchanged
    std::cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << std::endl;
    std::cout << "Top element is still: " << myPeek(st) << std::endl;
    
    // Check if an element is in the stack
    std::string target = "hello";
    if (doesContains(st, target)) {
        std::cout << target << " is in the stack." << std::endl;
    } else {
        std::cout << target << " is not in the stack." << std::endl;
    }
    
    return 0;
}
