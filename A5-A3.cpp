//  Given a linked list, remove the loop if it exists.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    // Insert at end 
    void insert(int val) {
        Node* node = new Node(val);
        if (!head) {
            head = node;
            return;
        }
        Node* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
    }

    // loop: tail->next = node at position pos (1-based).
    // If pos == 0, no loop created.
    void createLoop(int pos) {
        if (pos <= 0) return;
        Node* tail = head;
        Node* joinNode = nullptr;
        int idx = 1;
        while (tail && tail->next) {
            if (idx == pos) joinNode = tail;
            tail = tail->next;
            idx++;
        }
        // check last node and the possibility that pos is at last node
        if (tail && idx == pos) joinNode = tail;

        if (tail && joinNode) {
            tail->next = joinNode;
            cout << "Loop created: tail connects to node with value " << joinNode->data << " (position " << pos << ").\n";
        } else {
            cout << "Could not create loop (position out of range or empty list).\n";
        }
    }

    // Detect loop using Floyd's algorithm. Returns the meeting node if loop exists, else nullptr.
    Node* detectLoop() {
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return slow; // meeting point
        }
        return nullptr;
    }

    // Remove loop if it exists. Returns true if a loop was found & removed.
    bool removeLoop() {
        Node* meeting = detectLoop();
        if (!meeting) {
            return false; // no loop
        }

        Node* ptr1 = head;
        Node* ptr2 = meeting;

        // If the loop starts at head (special case), move ptr2 to last node of loop
        if (ptr1 == ptr2) {
            while (ptr2->next != ptr1) {
                ptr2 = ptr2->next;
            }
            // ptr2 is last node in loop
            ptr2->next = nullptr;
            return true;
        }

        // Otherwise, move both pointers at same speed until their next pointers are same
        while (ptr1->next != ptr2->next) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        // ptr2->next is the start of loop; break it
        ptr2->next = nullptr;
        return true;
    }

    // display upto 'limit' nodes to avoid infinite loop 
    void display(int limit = 50) const {
        Node* cur = head;
        int cnt = 0;
        while (cur && cnt < limit) {
            cout << cur->data;
            cur = cur->next;
            if (cur) cout << "->";
            cnt++;
        }
        if (cur) cout << "->... (continues; stopped after " << limit << " nodes to avoid infinite loop)";
        cout << "\n";
    }

    // Free nodes (useful if no loop exists)
    void freeAll() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
    }

    ~LinkedList() {
        // Attempt to remove loop (if any) to safely free nodes
        removeLoop();
        freeAll();
    }
};

int main() {
    LinkedList list;

    // Build list: 1->2->3->4->5->6
    for (int i = 1; i <= 6; ++i) list.insert(i);

    cout << "Initial list (safe display): ";
    list.display();

    // Create a loop: tail -> node at position 3 (node with value 3)
    list.createLoop(3);

    // Detect loop
    Node* meet = list.detectLoop();
    if (meet) {
        cout << "Loop detected (meeting node value = " << meet->data << ").\n";
    } else {
        cout << "No loop detected.\n";
    }

    // Attempt to remove loop
    bool removed = list.removeLoop();
    if (removed) {
        cout << "Loop removed successfully.\n";
    } else {
        cout << "No loop to remove.\n";
    }

    // Display list after removal
    cout << "List after removing loop: ";
    list.display();

    return 0;
}
