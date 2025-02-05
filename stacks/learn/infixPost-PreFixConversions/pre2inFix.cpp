#include <iostream>
#include <stack>
#include <string>
using namespace std;

string pre2inFix(string s) {
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (isalpha(s[i]) || isdigit(s[i])) {
            st.push(string(1, s[i]));
        } else {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            string temp = "";
            temp = "(" + t1 + s[i] + t2 + ")";
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string prefix = "*+AB-CD";  // Example prefix expression
    string infix = pre2inFix(prefix);
    cout << "Prefix Expression: " << prefix << endl;
    cout << "Infix Expression: " << infix << endl;
    return 0;
}
