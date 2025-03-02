#include <stack>
#include <vector>
#include <iostream>
using namespace std;

vector<int> genPSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> pse(n, -1);
    stack<int> st; // Monotonic increasing stack
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return pse;
}

vector<int> genNSE(vector<int> &arr) {
    int n = arr.size();
    vector<int> nse(n, n);
    stack<int> st; // Monotonic increasing stack
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            nse[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    return nse;
}

int sumSubarrayMins(vector<int> &arr) {
    const int MOD = 1e9 + 7;
    int n = arr.size();
    long long sum = 0;

    vector<int> pse = genPSE(arr);
    vector<int> nse = genNSE(arr);

    for (int i = 0; i < n; i++) {
        long long left = (i - pse[i]);   // Number of subarrays ending at i
        long long right = (nse[i] - i);  // Number of subarrays starting at i
        sum = (sum + (left * right % MOD) * arr[i] % MOD) % MOD;
    }
    return sum;
}

int main() {
    vector<int> arr = {3, 1, 2, 4};
    vector<int> pse = genPSE(arr);
    for(int i = 0; i < pse.size(); i+= 1){
        cout << pse[i] << " ";
    }
    cout << endl;
    cout << sumSubarrayMins(arr) << endl;  // Expected output: 17
    return 0;
}
