// Given a queue with random elements, we need to sort it. We are not allowed to use extra space. The 
// operations allowed on queue are:  
// 1.   enqueue() : Adds an item to rear of queue.  
// 2. dequeue() : Removes an item from front of queue.  
// 3. isEmpty() : Checks if a queue is empty.  
// Input: 11, 5, 4, 21  
// Output: 4, 5, 11, 21 
// https://www.geeksforgeeks.org/sorting-queue-without-extra-space/ 

#include <iostream>
#include <queue>
using namespace std;

// find index of minimum element within first n elements
int findMinIndex(queue<int> &q, int sortedIndex) {
    int minIndex = -1;
    int minValue = INT_MAX;
    int size = q.size();

    for (int i = 0; i < size; i++) {
        int cur = q.front();
        q.pop();

        // Only search unsorted portion
        if (i <= sortedIndex && cur < minValue) {
            minValue = cur;
            minIndex = i;
        }

        q.push(cur);   // rotate back
    }

    return minIndex;
}

// move min element at minIndex to the rear
void moveMinToRear(queue<int> &q, int minIndex) {
    int size = q.size();
    int minValue;

    for (int i = 0; i < size; i++) {
        int cur = q.front();
        q.pop();

        if (i != minIndex) {
            q.push(cur);
        } else {
            minValue = cur; // hold minimum
        }
    }

    q.push(minValue); // push minimum to rear
}

// sort queue without using extra space
void sortQueue(queue<int> &q) {
    int n = q.size();

    for (int i = n - 1; i >= 0; i--) {
        int minIndex = findMinIndex(q, i);
        moveMinToRear(q, minIndex);
    }
}

int main() {
    queue<int> q;

    // Sample input
    int arr[] = {11, 5, 4, 21};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++)
        q.push(arr[i]);

    cout << "Original Queue: ";
    queue<int> t = q;
    while (!t.empty()) {
        cout << t.front() << " ";
        t.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
