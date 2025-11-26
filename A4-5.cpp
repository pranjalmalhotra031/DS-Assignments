// Write a program to implement a stack using (a) Two queues and (b) One Queue. 

#include <iostream>
#include <queue>
using namespace std;

/*
  Stack using TWO queues (push-costly)
  - push(x): enqueue x into q2, move all elements from q1 -> q2, swap q1 and q2
  - pop(): dequeue from q1
  - top(): front of q1
  Complexity:
    push: O(n), pop: O(1), top: O(1), space: O(n)
*/

class StackUsingTwoQueues {
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x) {
        // Enqueue to q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap q1 and q2 (q1 now has the new order)
        swap(q1, q2);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cerr << "Stack is empty. top() called.\n";
            return -1; 
        }
        return q1.front();
    }

    bool isEmpty() const {
        return q1.empty();
    }

    // print stack from top -> bottom
    void display() {
        if (q1.empty()) {
            cout << "Stack (top->bottom): [ empty ]\n";
            return;
        }
        cout << "Stack (top->bottom): ";
        // copy queue to iterate without modifying original
        queue<int> temp = q1;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};


/*
  Stack using ONE queue (rotation method)
  - push(x): enqueue x, then rotate the queue size-1 times (move front to back)
  - pop(): dequeue
  - top(): front
  Complexity:
    push: O(n), pop: O(1), top: O(1), space: O(n)
*/

class StackUsingOneQueue {
private:
    queue<int> q;

public:
    void push(int x) {
        q.push(x);
        // rotate previous elements behind x
        int sz = q.size();
        for (int i = 0; i < sz - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack is empty. Cannot pop.\n";
            return;
        }
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cerr << "Stack is empty. top() called.\n";
            return -1;
        }
        return q.front();
    }

    bool isEmpty() const {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack (top->bottom): [ empty ]\n";
            return;
        }
        cout << "Stack (top->bottom): ";
        queue<int> temp = q;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\n";
    }
};


int main() {
    cout << "Demo: Stack using TWO queues (push-costly)\n";
    StackUsingTwoQueues s2;
    s2.push(10); s2.push(20); s2.push(30);
    s2.display();               // expected top->bottom: 30 20 10
    cout << "Top: " << s2.top() << "\n"; // 30
    s2.pop();
    cout << "After pop:\n";
    s2.display();               // 20 10
    cout << (s2.isEmpty() ? "Empty\n" : "Not Empty\n");

    cout << "\nDemo: Stack using ONE queue (rotation)\n";
    StackUsingOneQueue s1;
    s1.push(100); s1.push(200); s1.push(300);
    s1.display();               // expected top->bottom: 300 200 100
    cout << "Top: " << s1.top() << "\n"; // 300
    s1.pop();
    cout << "After pop:\n";
    s1.display();               // 200 100
    cout << (s1.isEmpty() ? "Empty\n" : "Not Empty\n");

    return 0;
}
