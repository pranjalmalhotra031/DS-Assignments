// Given a Doubly linked list containing n nodes. The task is to reverse every group of k 
// nodes in the list. If the number of nodes is not a multiple of k then left-out nodes, in the 
// end should be considered as a group and must be reversed. 
// https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/  
// Example 1: 
// Input:   1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL,   k = 2 
// Output: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5 <-> NULL. 
// Example 2: 
// Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> NULL, k = 4 
// Output: 4 <-> 3 <-> 2 <-> 1 <-> 6 -> 5 <-> NULL.  

#include <iostream>
using namespace std;

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

// append node at end (for building list)
void append(DNode*& head, int val) {
    DNode* node = new DNode(val);
    if (!head) {
        head = node;
        return;
    }
    DNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
    node->prev = cur;
}

// print list forward
void printForward(DNode* head) {
    DNode* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) cout << " <-> ";
        cur = cur->next;
    }
    cout << " -> NULL\n";
}

// Reverse every group of k nodes in a doubly linked list.
// If nodes remaining < k, they are reversed as well.
DNode* reverseInGroups(DNode* head, int k) {
    if (!head || k <= 1) return head;

    DNode* current = head;
    DNode* newHead = nullptr;      // head of new list after reversals
    DNode* prevGroupTail = nullptr; // tail of the previous processed group

    while (current) {
        // groupHead is the first node of current group (will become tail after reversal)
        DNode* groupHead = current;
        DNode* prev = nullptr;
        int count = 0;

        // Reverse up to k nodes
        while (current && count < k) {
            DNode* nextNode = current->next;

            // Reverse pointers for current
            current->next = prev;
            current->prev = nextNode; // after reversal, prev pointer should point to old next

            // move prev and current forward
            prev = current;
            current = nextNode;

            count++;
        }

        // prev is new head of this reversed group
        if (!newHead) {
            newHead = prev; // first group's head becomes overall new head
        }

        // connect previous group to current group's head
        if (prevGroupTail) {
            prevGroupTail->next = prev;
            if (prev) prev->prev = prevGroupTail;
        }

        // now groupHead is tail of this group (it was the initial head)
        // connect its next to current (head of next group or nullptr)
        groupHead->next = current;
        if (current) current->prev = groupHead;

        // prepare for next iteration
        prevGroupTail = groupHead;
    }

    return newHead;
}

// Free list
void freeList(DNode*& head) {
    DNode* cur = head;
    while (cur) {
        DNode* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    head = nullptr;
}

int main() {
    // Example 1:
    // Input:  1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 -> NULL, k = 2
    // Output: 2 <-> 1 <-> 4 <-> 3 <-> 6 <-> 5 -> NULL.
    {
        DNode* head = nullptr;
        int arr[] = {1,2,3,4,5,6};
        for (int x : arr) append(head, x);
        cout << "Original (Example 1): ";
        printForward(head);

        int k = 2;
        head = reverseInGroups(head, k);
        cout << "Reversed in groups of " << k << ": ";
        printForward(head);

        freeList(head);
        cout << "\n";
    }

    // Example 2:
    // Input: 1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 -> NULL, k = 4
    // Output: 4 <-> 3 <-> 2 <-> 1 <-> 6 <-> 5 -> NULL.
    {
        DNode* head = nullptr;
        int arr[] = {1,2,3,4,5,6};
        for (int x : arr) append(head, x);
        cout << "Original (Example 2): ";
        printForward(head);

        int k = 4;
        head = reverseInGroups(head, k);
        cout << "Reversed in groups of " << k << ": ";
        printForward(head);

        freeList(head);
    }

    return 0;
}
