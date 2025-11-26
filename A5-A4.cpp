// Given a linked list, and an integer k, rotate the list to the left by k positions and return 
// the updated head.  

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Rotate list left by k positions and return new head
Node* rotateLeft(Node* head, int k) {
    if (!head || k == 0) return head;

    // Compute length and get tail
    Node* tail = head;
    int n = 1;
    while (tail->next) {
        tail = tail->next;
        ++n;
    }

    // Normalize k
    k = k % n;
    if (k == 0) return head;

    // Find k-th node (new tail)
    Node* newTail = head;
    for (int i = 1; i < k; ++i) {
        newTail = newTail->next;
    }
    Node* newHead = newTail->next;

    // Make the list circular and then break
    tail->next = head;       // connect old tail to old head
    newTail->next = nullptr; // break to form new list starting at newHead

    return newHead;
}

// insert at end
void insertEnd(Node*& head, int val) {
    Node* node = new Node(val);
    if (!head) {
        head = node;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

// print list
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) cout << "->";
        cur = cur->next;
    }
    cout << "->NULL\n";
}

int main() {
    // Example: 1->2->3->4->5 and k = 2 -> rotate left by 2 -> 3->4->5->1->2
    Node* head = nullptr;
    int arr[] = {1,2,3,4,5};
    for (int x : arr) insertEnd(head, x);

    cout << "Original list: ";
    printList(head);

    int k = 2;
    head = rotateLeft(head, k);

    cout << "After rotating left by " << k << ": ";
    printList(head);

    return 0;
}
