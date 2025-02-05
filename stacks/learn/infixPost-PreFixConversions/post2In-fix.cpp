#include <iostream>
#include <stack>
#include <string>
using namespace std;

string post2inFix(const string &s) {
    stack<string> st;

    for (char c : s) {
        if (isalpha(c) || isdigit(c)) {
            st.push(string(1,c));
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();

            string temp = "(" + left + c + right + ")";
            st.push(temp);
        }
    }

    return st.top();
}

int main() {
    cout << post2inFix("21+3*") << endl;      // (a+b)
    cout << post2inFix("abc*+") << endl;    // (a+(b*c))
    cout << post2inFix("ab*cd/+") << endl;  // ((a*b)+(c/d))

    return 0;
}
