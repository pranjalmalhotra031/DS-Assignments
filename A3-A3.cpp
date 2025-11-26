//  Given an array arr[ ] of integers, the task is to find the Next Greater Element for each element of the 
// array in order of their appearance in the array. Note: The Next Greater Element for an element x is 
// the first greater element on the right side of x in the array. Elements for which no greater element 
// exist, consider the next greater element as -1.  
// Next Greater Element (NGE) for every element in given Array - GeeksforGeeks

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElement(vector<int> &arr) {
    int n = arr.size();
    vector<int> nge(n);
    stack<int> st;  // will store elements (not indexes)

    for (int i = n - 1; i >= 0; i--) {
        // Pop all smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack empty -> no greater element exists
        if (st.empty())
            nge[i] = -1;
        else
            nge[i] = st.top();

        // Push the current element
        st.push(arr[i]);
    }

    return nge;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> result = nextGreaterElement(arr);

    for (int x : result)
        cout << x << " ";

    return 0;
}
