#include <iostream>
#include <vector>
#include <stack>

/**
 * @brief Finds the next greater element for each element in the given array.
 * 
 * This function uses a monotonic stack to efficiently compute the next greater element
 * (NGE) for each element in the input array. The next greater element for an element x 
 * is the first element to its right that is greater than x.
 * 
 * @param nums A vector of integers representing the input array.
 * @return A vector of integers where each element represents the NGE of the corresponding input element.
 */
std::vector<int> nextGreaterElement(std::vector<int> nums) {
    std::vector<int> ans(nums.size());  
    std::stack<int> st;

    /**
     * @details Algorithm:
     * - Iterate over the array from right to left.
     * - Maintain a stack to store potential next greater elements.
     * - For each element:
     *   1. Pop elements from the stack while they are smaller than or equal to the current element.
     *   2. If the stack is empty after popping, there is no greater element; store -1.
     *   3. Otherwise, the stack's top is the next greater element; store it.
     *   4. Push the current element onto the stack for future comparisons.
     */
    for (int i = nums.size() - 1; i >= 0; i--) {
        //Pop element until either of them satisfied.
        while (!st.empty() && nums[i] >= st.top()) {
            st.pop();
        }
        
        if (st.empty()) {
            ans[i] = -1;  // No greater element found
        } else {
            ans[i] = st.top();  // Next greater element found
        }

        st.push(nums[i]);  // Push current element onto the stack
    }
    
    return ans;
}

int main() {
    // Sample input array
    std::vector<int> nums = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};

    // Compute next greater elements
    std::vector<int> ans = nextGreaterElement(nums);

    // Output the results
    std::cout << "Next Greater Elements: ";
    for (int n : ans) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
