#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/**
 * @brief Finds the previous smaller element for each element in the input vector.
 *
 * @details This function calculates the previous smaller element for each element in the input vector `A`.
 * It uses a stack to efficiently find the previous smaller element for each element in linear time.
 *
 * @param A The input vector containing integers for which the previous smaller elements are to be found.
 * @return vector<int> A vector containing the previous smaller element for each element in `A`. If no such element exists, -1 is stored.
 */
vector<int> prevSmaller(vector<int> &A) {
    vector<int> ans;
    ans.resize(A.size());

    stack<int> st;

    /**
     * @details Algorithm:
     * - Iterate over the array from left to right.
     * - Maintain a stack to store potential previous smaller elements.
     * - For each element:
     *   1. Pop elements from the stack while they are larger than or equal to the current element.
     *   2. If the stack is empty after popping, there is no previous smaller element; store -1.
     *   3. Otherwise, the stack's top is the previous smaller element; store it.
     *   4. Push the current element onto the stack for future comparisons.
     */
    for (int i = 0; i < A.size(); i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();
        }
        st.push(A[i]);
    }
    return ans;
}

/**
 * @brief Entry point of the program.
 *
 * @details This function demonstrates the usage of the `prevSmaller` function by passing a sample vector
 * and printing the results.
 *
 * @return int Returns 0 to indicate successful execution.
 */
int main() {
    std::vector<int> nums = {4, 5, 2, 10, 8};
    std::vector<int> ans = prevSmaller(nums);

    // Print the results
    for (const auto num : ans) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
