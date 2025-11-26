//  Given a Queue consisting of first n natural numbers (in random order). The task is to check whether 
// the given Queue elements can be arranged in increasing order in another Queue using a stack. The 
// operation allowed are:  
// 1. Push and pop elements from the stack  
// 2. Pop (Or Dequeue) from the given Queue.  
// 3. Push (Or Enqueue) in the another Queue. 
// Input : Queue[] = { 5, 1, 2, 3, 4 }  
// Output : Yes  
// Check if a queue can be sorted into another queue using a stack - GeeksforGeeks 

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

bool canBeSortedUsingStack(queue<int> q) {
    int n = q.size();
    if (n == 0) return true;

    stack<int> st;
    int expected = 1; // produce 1,2,3,...,n in order

    while (!q.empty()) {
        if (q.front() == expected) {
            // Directly send to output
            q.pop();
            expected++;
        } else if (!st.empty() && st.top() == expected) {
            // Top of stack can be sent to output
            st.pop();
            expected++;
        } else {
            // Move from queue to stack
            st.push(q.front());
            q.pop();
        }
    }

    // After input queue is exhausted, pop remaining stack elements
    while (!st.empty() && st.top() == expected) {
        st.pop();
        expected++;
    }

    // If produced all numbers 1..n, it's possible
    return (expected == n + 1);
}

int main() {
    // Example: Queue = {5, 1, 2, 3, 4}
    vector<int> arr = {5, 1, 2, 3, 4};
    queue<int> q;
    for (int x : arr) q.push(x);

    cout << "Input queue: ";
    queue<int> tmp = q;
    while (!tmp.empty()) { cout << tmp.front() << " "; tmp.pop(); }
    cout << "\n";

    bool possible = canBeSortedUsingStack(q);
    cout << (possible ? "Yes\n" : "No\n");

    return 0;
}
