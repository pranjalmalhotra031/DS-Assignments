// Implement Heapsort (Increasing/Decreasing order).

#include <bits/stdc++.h>
using namespace std;

// Sift-down for max-heap (used for ascending sort)
template<typename T>
void siftDownMax(vector<T> &a, size_t start, size_t end) {
    size_t root = start;
    while (true) {
        size_t left = 2 * root + 1;
        if (left > end) break;
        size_t swap_idx = left;
        size_t right = left + 1;
        if (right <= end && a[right] > a[left]) swap_idx = right;
        if (a[swap_idx] > a[root]) {
            swap(a[root], a[swap_idx]);
            root = swap_idx;
        } else {
            break;
        }
    }
}

// Heapsort ascending: build max-heap, then extract
template<typename T>
void heapsort_ascending(vector<T> &a) {
    if (a.size() < 2) return;
    size_t n = a.size();

    // Build max-heap
    for (int i = static_cast<int>((n - 2) / 2); i >= 0; --i) {
        siftDownMax(a, static_cast<size_t>(i), n - 1);
        if (i == 0) break; // prevent underflow for unsigned index
    }

    // Extract elements
    for (size_t end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);            // move current max to its final place
        siftDownMax(a, 0, end - 1);   // restore heap on reduced range
    }
}

// Sift-down for min-heap (used for descending sort)
template<typename T>
void siftDownMin(vector<T> &a, size_t start, size_t end) {
    size_t root = start;
    while (true) {
        size_t left = 2 * root + 1;
        if (left > end) break;
        size_t swap_idx = left;
        size_t right = left + 1;
        if (right <= end && a[right] < a[left]) swap_idx = right;
        if (a[swap_idx] < a[root]) {
            swap(a[root], a[swap_idx]);
            root = swap_idx;
        } else {
            break;
        }
    }
}

// Heapsort descending: build min-heap, then extract
template<typename T>
void heapsort_descending(vector<T> &a) {
    if (a.size() < 2) return;
    size_t n = a.size();

    // Build min-heap
    for (int i = static_cast<int>((n - 2) / 2); i >= 0; --i) {
        siftDownMin(a, static_cast<size_t>(i), n - 1);
        if (i == 0) break;
    }

    // Extract elements
    for (size_t end = n - 1; end > 0; --end) {
        swap(a[0], a[end]);             // move current min to its final place
        siftDownMin(a, 0, end - 1);     // restore heap on reduced range
    }
}

int main() {
    vector<int> v1 = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    vector<int> v2 = v1;

    heapsort_ascending(v1);
    heapsort_descending(v2);

    cout << "Ascending: ";
    for (auto &x : v1) cout << x << ' ';
    cout << '\n';

    cout << "Descending: ";
    for (auto &x : v2) cout << x << ' ';
    cout << '\n';

    return 0;
}
