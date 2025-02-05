#include <iostream>
#include <stack>

using namespace std;

int priority(char s) {
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

string infixToPostFixConversion(string s) {
    stack<char> st;
    string ans = "";
    int size = s.size();
    int i = 0;
    while (i < size) {
        //conditions checklist:
        //1. check for operands, if found add that into ans
        //2. check for Opening braces if found add that into stack
        //3. check for Closing brackets if found removed all the elements until the opening bracket not found,
        //and add them into ans and then remove the opening braces
        //4. lastly for operators add them into stack by comparing their priority and then push it into stack or ans.
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            ans += s[i];
        } else if (s[i] == '(') {
            st.push(s[i]);
        } else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();  // Remove '(' from stack
        } else {
            while (!st.empty() && priority(s[i]) <= priority(st.top())) {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    //lasltly add everything into ans string and return it.
    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string exp = "(p+q)*(m-n)";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: " << infixToPostFixConversion(exp) << endl;
    return 0;
}
