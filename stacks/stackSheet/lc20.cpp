// Example 1:
// Input: s = "()"
// Output: true
// Example 2:
// Input: s = "()[]{}"
// Output: true
// Example 3:
// Input: s = "(]"
// Output: false
#include <iostream>
#include <stack>
#include <string>

bool isValid(std::string s) {
    // Approach: Use a stack to validate the string.
    std::stack<char> st;
    for (auto const &word : s) {
        if (word == ')' || word == '}' || word == ']') {
            if (st.empty()) {
                return false;  // No matching opening bracket
            }
            // Check if the top of the stack matches the current closing bracket
            if ((word == ')' && st.top() == '(') ||
                (word == '}' && st.top() == '{') ||
                (word == ']' && st.top() == '[')) {
                st.pop();  // Match found, pop the stack
            } else {
                return false;  // Mismatched pair
            }
        } else {
            // Push only opening brackets onto the stack
            st.push(word);
        }
    }
    // Stack must be empty for the string to be valid
    return st.empty();
}

int main() {
    // Example test cases
    std::string testCases[] = {"()", "()[]{}", "(]", "[({})]", "{[))"};
    int t = 5;  // Number of test cases

    for (int i = 0; i < t; ++i) {
        std::string s = testCases[i];
        bool result = isValid(s);
        std::cout << "Input: " << s
                  << "\nOutput: " << (result ? "true" : "false") << "\n\n";
    }

    return 0;
}
