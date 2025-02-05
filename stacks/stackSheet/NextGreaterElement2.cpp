#include <iostream>
#include <vector>
#include <stack>

/**
 * @brief Finds the next greater element in a circular array.
 *
 * Given an array, this function computes the next greater element (NGE) for each
 * element in the array. The array is treated as circular, meaning the search for
 * the next greater element wraps around the end of the array back to the beginning.
 *
 * @param nums A vector of integers for which the next greater elements need to be found.
 * @return A vector of integers containing the next greater element for each index.
 */
std::vector<int> nextGreaterElementII(std::vector<int> nums) {
    int n = nums.size();
    std::vector<int> ans(n, -1); // Initialize result array with -1
    std::stack<int> st;

    /**
     * @details Algorithm:
     * - Iterate from right to left, considering a hypothetical doubled array.
     * - Use modular arithmetic (`i % n`) to access elements in a circular manner.
     * - Maintain a monotonic decreasing stack to store potential NGEs.
     *   For each element:
     *     1. Pop elements from the stack that are smaller or equal to the current element.
     *     2. If in the original range (`i < n`), store the top of the stack as the NGE.
     *     3. If the stack is empty, assign -1.
     *     4. Push the current element onto the stack.
     */
    for (int i = 2 * n - 1; i >= 0; i--) {
        // Remove elements from stack that are less than or equal to the current element
        while (!st.empty() && st.top() <= nums[i % n]) {
            st.pop();
        }
        // Store result if within original array bounds
        if (i < n) {
            ans[i] = st.empty() ? -1 : st.top();
        }
        // Push current element to stack for future comparisons
        st.push(nums[i % n]);
    }
    return ans;
}

int main() {
    std::vector<int> n = {2, 10, 12, 1, 11};
    std::vector<int> ans = nextGreaterElementII(n);

    // Print the next greater elements
    for (const auto num : ans) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
