#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/**
 * Calculates the number of days until a warmer temperature.
 *
 * Given a vector of daily temperatures, this function returns a vector where
 * each element represents the number of days you must wait until a warmer temperature.
 * If no warmer day exists in the future, the value is set to 0.
 *
 * @param t A vector of integers representing the daily temperatures.
 * @return A vector of integers where each value is the number of days until a warmer temperature.
 */
vector<int> dailyTemperatures(vector<int>& t) {
    // Stack to store pairs of (temperature, index).
    // The stack will help us quickly find the next day with a higher temperature.
    stack<pair<int, int>> st;

    // Initialize the result vector with 0s.
    vector<int> ans(t.size(), 0);

    // Process the temperatures from right to left.
    for (int i = t.size() - 1; i >= 0; --i) {
        // Remove temperatures from the stack that are less than or equal to the current temperature.
        // They cannot be the "next warmer day" for any previous day.
        while (!st.empty() && st.top().first <= t[i]) {
            st.pop();
        }

        // If the stack is not empty, the top element is the next warmer day.
        // The difference in indices gives the number of days until a warmer temperature.
        ans[i] = st.empty() ? 0 : st.top().second - i;

        // Push the current temperature and its index onto the stack.
        st.push({t[i], i});
    }
    return ans;
}

int main() {
    vector<int> t = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> ans = dailyTemperatures(t);
    
    for (const auto n : ans) {
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}
