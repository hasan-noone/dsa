#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to convert postfix expression to prefix expression
string post2pre(string s) {
    stack<string> st; // Stack to store operands and intermediate results
    
    // Traverse the postfix expression from left to right
    for (char c : s) {
        // If the character is an operand (letter or digit), push it onto the stack
        if (isalpha(c) || isdigit(c)) {
            st.push(string(1, c)); // Convert char to string and push
        }
        // If the character is an operator, pop two operands and form a prefix expression
        else {
            // Pop the top two operands from the stack
            string operand1 = st.top(); // First operand
            st.pop();
            string operand2 = st.top(); // Second operand
            st.pop();
            
            // Create a prefix expression: operator + operand2 + operand1
            string prefixExpr = c + operand2 + operand1;
            
            // Push the newly formed prefix expression back onto the stack
            st.push(prefixExpr);
        }
    }
    
    // The final prefix expression is the only element left on the stack
    return st.top();
}

int main() {
    // Test postfix expressions
    string postfix1 = "AB+CD-*"; // Example: (A+B)*(C-D)
    string postfix2 = "ABC+-";   // Example: A-(B+C)
    
    // Convert and print prefix expressions
    cout << "Postfix: " << postfix1 << " -> Prefix: " << post2pre(postfix1) << endl;
    cout << "Postfix: " << postfix2 << " -> Prefix: " << post2pre(postfix2) << endl;
    
    return 0;
}
