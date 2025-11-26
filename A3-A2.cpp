// Design a stack that supports getMin() in O(1) time and O(1) extra space. 
// https://www.geeksforgeeks.org/design-a-stack-that-supports-getmin-in-o1-time-and-o1-extra- space/

#include <iostream>
#include <stack>
using namespace std;

class SpecialStack {
    stack<long long> st;
    long long minVal;

public:
    bool isEmpty() {
        return st.empty();
    }

    void push(long long x) {
        if (st.empty()) {
            st.push(x);
            minVal = x;
        }
        else if (x >= minVal) {
            st.push(x);
        }
        else {
            // encode the value
            long long encoded = 2LL * x - minVal;
            st.push(encoded);
            minVal = x;
        }
    }

    void pop() {
        if (st.empty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        long long topVal = st.top();
        st.pop();

        if (topVal < minVal) {
            // encoded value -> old min must be restored
            minVal = 2LL * minVal - topVal;
        }
    }

    long long top() {
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }

        long long topVal = st.top();
        if (topVal >= minVal)
            return topVal;
        else
            return minVal;  // encoded value -> actual top is minVal
    }

    long long getMin() {
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return minVal;
    }
};

int main() {
    SpecialStack s;

    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);

    cout << "Min: " << s.getMin() << endl; // 2

    s.pop();
    cout << "Min: " << s.getMin() << endl; // 3

    s.pop();
    cout << "Top: " << s.top() << endl;    // 3
    cout << "Min: " << s.getMin() << endl; // 3

    return 0;
}
