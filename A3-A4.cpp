// Given an array of integers temperatures represents the daily temperatures, return an 
// array answer such that answer[i] is the number of days you have to wait after the ith day to get a 
// warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead. 
// Daily Temperatures - LeetCode 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> ans(n, 0);
    stack<int> st;  // will store the indices

    for (int i = n - 1; i >= 0; i--) {
        // Pop all smaller or equal temperatures
        while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
            st.pop();
        }

        // Next warmer day exists
        if (!st.empty()) {
            ans[i] = st.top() - i;
        }

        // Push current index
        st.push(i);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    vector<int> result = dailyTemperatures(temperatures);

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
