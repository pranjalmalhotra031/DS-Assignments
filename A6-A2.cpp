// Given a Doubly linked list and Circular singly linked list containing N nodes, the task is 
// to remove all the nodes from each list which contains elements whose parity is even.  
// https://www.geeksforgeeks.org/remove-all-even-parity-nodes-from-a-doubly-and
// circular-singly-linked-list/  
// Note: Parity means no of 1 in binary form 
// 11 -> 1011, parity = 3  
// 15 -> 1111, parity = 4  
// Example 1: 
// Input: CLL:  9 -> 11 -> 34 -> 6 -> 13 -> 21  
// Output: 11 -> 13 -> 21 
// Example 2: 
// Input: DLL: 18 <=> 15 <=> 8 <=> 9 <=> 14  
// Output: 8 <=> 14 

#include <iostream>
using namespace std;

// ----------------------
// parity check
// returns true if number of 1-bits is even
// ----------------------
bool hasEvenParity(unsigned int x) {
    int ones = __builtin_popcount(x);
    return (ones % 2) == 0;
}

// ----------------------
// Circular Singly Linked List (CSLL)
// ----------------------
struct CNode {
    int data;
    CNode* next;
    CNode(int d) : data(d), next(nullptr) {}
};

// Print CSLL (single traversal). If head==nullptr, prints "Empty".
void printCircular(CNode* head) {
    if (!head) {
        cout << "Empty\n";
        return;
    }
    CNode* cur = head;
    bool first = true;
    do {
        if (!first) cout << " -> ";
        cout << cur->data;
        first = false;
        cur = cur->next;
    } while (cur != head);
    cout << "\n";
}

// Remove nodes with even parity from circular list.
// head is passed by reference and may be updated.
void removeEvenParityCircular(CNode*& head) {
    if (!head) return;

    // Handle single node case
    if (head->next == head) {
        if (hasEvenParity((unsigned int)head->data)) {
            delete head;
            head = nullptr;
        }
        return;
    }

    // We will iterate through list keeping track of prev and curr.
    CNode* prev = head;
    CNode* curr = head->next;

    // First, handle potential removal of head nodes at the beginning (head might need removal).
    // use a loop that attempts to remove head until head is not to be removed or list becomes empty/single.
    while (hasEvenParity((unsigned int)head->data)) {
        // remove head node
        // find tail (node whose next is head)
        CNode* tail = head;
        while (tail->next != head) tail = tail->next;

        CNode* toDel = head;
        if (head->next == head) { // one node only (handled above, but kept for safety)
            delete toDel;
            head = nullptr;
            return;
        } else {
            head = head->next;
            tail->next = head;
            delete toDel;
        }
        // if head now becomes nullptr or single node handled next
        if (!head) return;
        if (head->next == head) {
            if (hasEvenParity((unsigned int)head->data)) {
                delete head;
                head = nullptr;
            }
            return;
        }
    }

    // Now head is safe (has odd parity). We can remove other nodes by traversing once.
    prev = head;
    curr = head->next;
    while (curr != head) {
        if (hasEvenParity((unsigned int)curr->data)) {
            // remove curr
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
}

// ----------------------
// Doubly Linked List (DLL)
// ----------------------
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

// Print DLL from head to tail
void printDoubly(DNode* head) {
    if (!head) {
        cout << "Empty\n";
        return;
    }
    DNode* cur = head;
    bool first = true;
    while (cur) {
        if (!first) cout << " <=> ";
        cout << cur->data;
        first = false;
        cur = cur->next;
    }
    cout << "\n";
}

// Remove nodes with even parity from doubly linked list.
// head passed by reference
void removeEvenParityDoubly(DNode*& head) {
    DNode* cur = head;
    while (cur) {
        DNode* nextNode = cur->next;
        if (hasEvenParity((unsigned int)cur->data)) {
            // delete cur
            if (cur->prev) cur->prev->next = cur->next;
            else head = cur->next; // cur was head

            if (cur->next) cur->next->prev = cur->prev;
            delete cur;
        }
        cur = nextNode;
    }
}

// ----------------------
// Helper builders for examples
// ----------------------
CNode* buildCircularFromArray(const int arr[], int n) {
    if (n == 0) return nullptr;
    CNode* head = new CNode(arr[0]);
    CNode* tail = head;
    for (int i = 1; i < n; ++i) {
        tail->next = new CNode(arr[i]);
        tail = tail->next;
    }
    tail->next = head; // make circular
    return head;
}

DNode* buildDoublyFromArray(const int arr[], int n) {
    if (n == 0) return nullptr;
    DNode* head = new DNode(arr[0]);
    DNode* cur = head;
    for (int i = 1; i < n; ++i) {
        DNode* node = new DNode(arr[i]);
        cur->next = node;
        node->prev = cur;
        cur = node;
    }
    return head;
}

// Free circular list nodes (break circle then free)
void freeCircular(CNode*& head) {
    if (!head) return;
    // break circle
    CNode* tail = head;
    while (tail->next != head) tail = tail->next;
    tail->next = nullptr;
    // free linear list
    CNode* cur = head;
    while (cur) {
        CNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
}

// Free doubly list nodes
void freeDoubly(DNode*& head) {
    DNode* cur = head;
    while (cur) {
        DNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
}

// ----------------------
// Demonstration main()
// ----------------------
int main() {
    // Example 1: Circular list: 9 -> 11 -> 34 -> 6 -> 13 -> 21  (result: 11 -> 13 -> 21)
    int arr1[] = {9, 11, 34, 6, 13, 21};
    CNode* chead = buildCircularFromArray(arr1, sizeof(arr1)/sizeof(arr1[0]));

    cout << "Original Circular List: ";
    printCircular(chead);

    removeEvenParityCircular(chead);

    cout << "After removing even-parity nodes: ";
    printCircular(chead); // expected: 11 -> 13 -> 21

    freeCircular(chead);

    cout << "\n";

    // Example 2: Doubly list: 18 <=> 15 <=> 8 <=> 9 <=> 14  (result: 8 <=> 14)
    int arr2[] = {18, 15, 8, 9, 14};
    DNode* dhead = buildDoublyFromArray(arr2, sizeof(arr2)/sizeof(arr2[0]));

    cout << "Original Doubly List: ";
    printDoubly(dhead);

    removeEvenParityDoubly(dhead);

    cout << "After removing even-parity nodes: ";
    printDoubly(dhead); // expected: 8 <=> 14

    freeDoubly(dhead);

    return 0;
}
