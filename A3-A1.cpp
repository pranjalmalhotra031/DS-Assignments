// Given an array A, find the nearest smaller element for every element A[i] in the array such that the 
// element has an index smaller than i. 
// https://www.interviewbit.com/problems/nearest-smaller-element/ 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nearestSmaller(vector<int> &A) {
    int n = A.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= A[i]) {
            st.pop();
        }

        if (st.empty())
            ans[i] = -1;
        else
            ans[i] = st.top();

        st.push(A[i]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    vector<int> res = nearestSmaller(A);

    for (int x : res)
        cout << x << " ";

    return 0;
}
