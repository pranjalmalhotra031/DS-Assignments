// Write a program interleave the first half of the queue with second half. 
//Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    int n = q.size();

    if (n % 2 != 0) {
        cout << "Queue must contain even number of elements.\n";
        return;
    }

    int half = n / 2;
    queue<int> firstHalf;

    // Push first half into another queue
    for (int i = 0; i < half; i++) {
        firstHalf.push(q.front());
        q.pop();
    }

    // interleave: firstHalf + remaining elements in q
    while (!firstHalf.empty()) {
        q.push(firstHalf.front());
        firstHalf.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;

    // Sample input
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
