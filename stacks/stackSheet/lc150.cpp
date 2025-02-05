#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to evaluate Reverse Polish Notation
int evalPRN(vector<string>& tokens) {
    stack<int> st;
    for (const string& c : tokens) {
        if (c == "+" || c == "-" || c == "*" || c == "/") {
            int top1 = st.top();
            st.pop();
            int top2 = st.top();
            st.pop();
            if (c == "+") {
                st.push(top2 + top1);
            } else if (c == "-") {
                st.push(top2 - top1);
            } else if (c == "*") {
                st.push(top2 * top1);
            } else if (c == "/") {
                st.push(top2 / top1);
            }
        } else {
            st.push(stoi(c));
        }
    }
    return st.top();
}

int main() {
    vector<string> tokens = {"2", "1", "+", "3", "*"}; // Example input: (2 + 1) * 3
    int result = evalPRN(tokens);
    cout << "Result: " << result << endl;
    return 0;
}
