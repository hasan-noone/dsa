#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to convert prefix expression to postfix expression
string pre2post(string s) {
    stack<string> st; // Stack to store operands and intermediate results
    
    // Traverse the prefix expression from right to left
    for (int i = s.length() - 1; i >= 0; i--) {
        char c = s[i];
        
        // If the character is an operand (letter or digit), push it onto the stack
        if (isalpha(c) || isdigit(c)) {
            st.push(string(1, c)); // Convert char to string and push
        }
        // If the character is an operator, pop two operands and form a postfix expression
        else {
            // Pop the top two operands from the stack
            string operand1 = st.top(); // First operand
            st.pop();
            string operand2 = st.top(); // Second operand
            st.pop();
            
            // Create a postfix expression: operand1 + operand2 + operator
            string postfixExpr = operand1 + operand2 + c;
            
            // Push the newly formed postfix expression back onto the stack
            st.push(postfixExpr);
        }
    }
    
    // The final postfix expression is the only element left on the stack
    return st.top();
}

int main() {
    // Test prefix expressions
    string prefix1 = "*+AB-CD"; // Example: (A+B)*(C-D)
    string prefix2 = "-A+BC";   // Example: A-(B+C)
    
    // Convert and print postfix expressions
    cout << "Prefix: " << prefix1 << " -> Postfix: " << pre2post(prefix1) << endl;
    cout << "Prefix: " << prefix2 << " -> Postfix: " << pre2post(prefix2) << endl;
    
    return 0;
}
