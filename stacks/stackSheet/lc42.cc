#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int> &height){
    int total_sum = 0;
    int left,right,leftMax,rightMax;
    return total_sum;
}
int trapExtraSpaceApproach(vector<int> &height) { // tc -> O(3N) and sc -> O(2N)
    // will use a forumla to do it
    //  Summation of min(leftMax,rightMax) - arr[i] ; arr[i] < left/rigt-Max.
    int n = height.size();
    vector<int> prefixMax(n);
    vector<int> suffixMax(n);
    int total_sum = 0;
    // calculating prefix max
    prefixMax[0] = height[0];
    for (int i = 1; i < n; i += 1) {
        prefixMax[i] = max(height[i], prefixMax[i - 1]);
    }
    suffixMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i -= 1) {
        suffixMax[i] = max(suffixMax[i + 1], height[i]);
    }
    // now calulating the sum
    int leftMax, rightMax;
    for (int i = 0; i < n; i += 1) {
        leftMax = prefixMax[i];
        rightMax = suffixMax[i];
        if (height[i] < leftMax && height[i] < rightMax) {
            total_sum += min(leftMax, rightMax) - height[i];
        }
    }
    return total_sum;
}

int main() {
    vector<int> trappedWater = {4, 2, 0, 3, 2, 5};
    int storedWater = trapExtraSpaceApproach(trappedWater);
    cout << storedWater << endl;
    return 0;
}
