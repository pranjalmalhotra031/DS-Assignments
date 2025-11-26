// Implement priority queues using heaps. 

#include <bits/stdc++.h>
using namespace std;

class MaxPQ {
private:
    vector<int> heap;

    // Move element at index i down to maintain heap property
    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

    // Move element at index i up to maintain heap property
    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] >= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }

    int top() const {
        if (heap.empty()) throw runtime_error("PQ is empty");
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

class MinPQ {
private:
    vector<int> heap;

    void siftDown(int i) {
        int n = heap.size();
        while (true) {
            int left = 2*i + 1;
            int right = 2*i + 2;
            int smallest = i;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;
            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest == i) break;

            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }

    void siftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (heap[parent] <= heap[i]) break;
            swap(heap[parent], heap[i]);
            i = parent;
        }
    }

public:
    void push(int x) {
        heap.push_back(x);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) return;
        heap[0] = heap.back();
        heap.pop_back();
        siftDown(0);
    }

    int top() const {
        if (heap.empty()) throw runtime_error("PQ is empty");
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }

    int size() const {
        return heap.size();
    }
};

int main() {
    MaxPQ maxpq;
    maxpq.push(5);
    maxpq.push(1);
    maxpq.push(10);
    maxpq.push(3);

    cout << "MaxPQ top: " << maxpq.top() << "\n"; // 10
    maxpq.pop();
    cout << "MaxPQ top after pop: " << maxpq.top() << "\n"; // 5

    MinPQ minpq;
    minpq.push(5);
    minpq.push(1);
    minpq.push(10);
    minpq.push(3);

    cout << "MinPQ top: " << minpq.top() << "\n"; // 1
    minpq.pop();
    cout << "MinPQ top after pop: " << minpq.top() << "\n"; // 3

    return 0;
}
