// Example 1:
// Input: ops = ["5","2","C","D","+"]
// Output: 30
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "2" - Add 2 to the record, record is now [5, 2].
// "C" - Invalidate and remove the previous score, record is now [5].
// "D" - Add 2 * 5 = 10 to the record, record is now [5, 10].
// "+" - Add 5 + 10 = 15 to the record, record is now [5, 10, 15].
// The total sum is 5 + 10 + 15 = 30.

// Example 2:
// Input: ops = ["5","-2","4","C","D","9","+","+"]
// Output: 27
// Explanation:
// "5" - Add 5 to the record, record is now [5].
// "-2" - Add -2 to the record, record is now [5, -2].
// "4" - Add 4 to the record, record is now [5, -2, 4].
// "C" - Invalidate and remove the previous score, record is now [5, -2].
// "D" - Add 2 * -2 = -4 to the record, record is now [5, -2, -4].
// "9" - Add 9 to the record, record is now [5, -2, -4, 9].
// "+" - Add -4 + 9 = 5 to the record, record is now [5, -2, -4, 9, 5].
// "+" - Add 9 + 5 = 14 to the record, record is now [5, -2, -4, 9, 5, 14].
// The total sum is 5 + -2 + -4 + 9 + 5 + 14 = 27.
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    int calPoints(vector<string> &operations) {
        stack<int> st;

        for (const auto &op : operations) {
            if (op == "+") {
                // If the operation is "+", add the last two scores
                int top = st.top();
                st.pop();
                int other_top = st.top();
                st.push(top);  // Push back the first top element
                st.push(top +
                        other_top);  // Push the sum of the last two elements
            } else if (op == "D") {
                // If the operation is "D", double the last score
                st.push(st.top() * 2);
            } else if (op == "C") {
                // If the operation is "C", cancel the last score
                st.pop();
            } else {
                // If the operation is a number, convert it to an integer and
                // push it onto the stack
                int num = stoi(op);
                st.push(num);
            }
        }

        // Calculate the total sum of the scores in the stack
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

// Example usage
int main() {
    Solution solution;
    vector<string> operations = {"5", "2", "C", "D", "+"};
    int result = solution.calPoints(operations);
    cout << "The total score is: " << result << endl;  // Output should be 30
    return 0;
}
