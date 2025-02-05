#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string and flip parentheses
string reverse(string s) {
    stack<char> st;
    string rev = "";
    // Push each character onto the stack, flipping parentheses
    for (char c : s) {
        if (c == '(') {
            st.push(')');
        } else if (c == ')') {
            st.push('(');
        } else {
            st.push(c);
        }
    }
    // Pop from stack to build the reversed string
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    return rev;
}

// Function to return the priority of an operator
inline int priority(char s) {
    if (s == '^') {
        return 3;
    } else if (s == '*' || s == '/') {
        return 2;
    } else if (s == '+' || s == '-') {
        return 1;
    } else {
        return -1;
    }
}

// Function to convert infix to postfix
inline string infixToPostFixConversion(string s) {
    stack<char> st;
    string ans = "";
    for (char c : s) {
        // Check for operands
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
            (c >= '0' && c <= '9')) {
            ans += c;
        }
        // Check for opening parenthesis
        else if (c == '(') {
            st.push(c);
        }
        // Check for closing parenthesis
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();  // Remove '(' from stack
        }
        // Handle operators
        else {
            while (!st.empty() && priority(c) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    
    // Add remaining elements in the stack to the result
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string test = "x+y*z/w+u";
    // Step 1: Reverse the infix string and flip parentheses
    string reversed = reverse(test);
    // Step 2: Convert reversed infix to postfix
    string postfix = infixToPostFixConversion(reversed);
    // Step 3: Reverse the postfix to get the prefix
    string prefix = reverse(postfix);
    cout << "Infix: " << test << endl;
    cout << "Prefix: " << prefix << endl;
    return 0;
}
