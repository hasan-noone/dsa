#include <iostream>
#include <vector>

using namespace std;


vector<int> findNSE(vector<int> &nums){
    vector<int> nse(nums.size());
    stack<int> st;
    for(int i = nums.size() - 1;i >= 0; i --){
        while(!st.empty() && nums[st.top()] >= arr[i]){
            st.pop();
        }
        nse[i] = st.empty() ? num.size() - 1 : st.top();
       st.push(i);
    }
    return nse;
}

vector<int> findPSE(vector<int> &nums){
    vector<int> nse(nums.size());
}
int sumSubarrayMinsBrute(vector<int> &arr) {
    int mini = 0;
    int n = arr.size();
    for (int st = 0; st < n; st++) {
        int minVal = arr[st]; // Start with the first element of the subarray

        for (int end = st; end < n; end++) {
            minVal = min(minVal, arr[end]); // Update the minimum while expanding
            mini += minVal;
        }
    }
    return mini;
}
int sumSubarrayMins(vector<int> &arr){
    int sum = 0;

    return sum;
}
int main() {
    vector<int> nums = {3, 1, 2, 4};
    int res = sumSubarrayMinsBrute(nums);
    cout << res << endl; // Expected output: 17
    return 0;
}
