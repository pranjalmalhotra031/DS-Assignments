// Given a doubly linked list having exactly one of the node pointing to a random node in the 
// list, the task is to correct this random pointer in the doubly linked list, such that it points to 
// the expected node. 
// https://www.geeksforgeeks.org/correct-the-random-pointer-in-doubly-linked-list/ 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

class DoublyList {
public:
    Node* head;
    DoublyList() : head(nullptr) {}

    // Append to end (helper for building demo lists)
    void append(int val) {
        Node* node = new Node(val);
        if (!head) { head = node; return; }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
    }

    // Intentionally create a broken link for demo:
    // make node at position pos (1-based) point prev to wrong node (like prev = head)
    void breakPrevAt(int pos) {
        if (!head) return;
        Node* cur = head;
        int idx = 1;
        while (cur && idx < pos) { cur = cur->next; ++idx; }
        if (!cur || !cur->next) return;
        cur->next->prev = head;
    }

    void printForward() const {
        Node* cur = head;
        while (cur) {
            cout << cur->data << " (";
            if (cur->prev) cout << cur->prev->data; else cout << -1;
            cout << ") ";
            cur = cur->next;
        }
        cout << "\n";
    }

    // Correct inconsistent pointers in O(n)
    void correctPointers() {
        if (!head) return;

        // If head->next's prev is wrong, fix it.
        if (head->next && head->next->prev != head) {
            head->next->prev = head;
            return; // problem fixed 
        }

        // If head->prev is incorrectly non-null, reset it.
        if (head->prev != nullptr) {
            head->prev = nullptr;
            return;
        }

        // Traverse and check each node
        Node* temp = head->next;
        while (temp) {
            // If next's prev is wrong, fix and return
            if (temp->next && temp->next->prev != temp) {
                temp->next->prev = temp;
                return;
            }
            // Else if prev's next is wrong, fix and return
            else if (temp->prev && temp->prev->next != temp) {
                temp->prev->next = temp;
                return;
            }
            temp = temp->next;
        }
    }

    // free nodes
    void freeAll() {
        Node* cur = head;
        while (cur) {
            Node* t = cur;
            cur = cur->next;
            delete t;
        }
        head = nullptr;
    }

    ~DoublyList() {
        freeAll();
    }
};

int main() {
    // Build list: 1 <-> 2 <-> 3 <-> 4
    DoublyList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);

    cout << "Original (expected) list: \n";
    dll.printForward(); // prints data(prev)

    // Create a bad pointer : break prev for node '3'
    dll.breakPrevAt(2); // sets node 3's prev to head (wrong)

    cout << "\nAfter breaking (incorrect) pointers: \n";
    dll.printForward();

    // Correct the pointers
    dll.correctPointers();

    cout << "\nAfter correction: \n";
    dll.printForward();

    return 0;
}
