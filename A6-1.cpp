//  Develop a menu driven program for the following operations of on a Circular as well 
// as a Doubly Linked List. 
// (a) Insertion anywhere in the linked list (As a first node, as a last node, and 
// after/before a specific node). 
// (b) Deletion of a specific node, say 'Delete Node 60'. That mean the node to be 
// deleted may appear as a head node, last node or a node in between. 
// (c) Search for a node.

#include <iostream>
using namespace std;

/* ===========================
   Circular Singly Linked List
   Nodes: int data, next
   List keeps tail pointer (makes insert at beginning/end easy)
   ============================ */

struct CNode {
    int data;
    CNode* next;
    CNode(int d) : data(d), next(nullptr) {}
};

class CircularList {
private:
    CNode* tail; // tail->next is head
public:
    CircularList() : tail(nullptr) {}

    bool isEmpty() const { return tail == nullptr; }

    // display elements once around the circle
    void display() const {
        if (!tail) {
            cout << "Circular List is empty.\n";
            return;
        }
        cout << "Circular List: ";
        CNode* cur = tail->next; // head
        do {
            cout << cur->data;
            cur = cur->next;
            if (cur != tail->next) cout << " -> ";
        } while (cur != tail->next);
        cout << "\n";
    }

    // insert as first node
    void insertAtBeginning(int val) {
        CNode* node = new CNode(val);
        if (!tail) {
            tail = node;
            tail->next = tail;
        } else {
            node->next = tail->next;
            tail->next = node;
        }
        cout << val << " inserted at beginning of circular list.\n";
    }

    // insert at end
    void insertAtEnd(int val) {
        insertAtBeginning(val); // simpler: insert at beginning then move tail
        tail = tail->next;
        cout << val << " inserted at end of circular list.\n";
    }

    // insert after first occurrence of target
    void insertAfter(int target, int val) {
        if (!tail) {
            cout << "List empty. Cannot insert after " << target << ".\n";
            return;
        }
        CNode* cur = tail->next; // head
        bool found = false;
        do {
            if (cur->data == target) {
                found = true;
                break;
            }
            cur = cur->next;
        } while (cur != tail->next);

        if (!found) {
            cout << "Value " << target << " not found in circular list.\n";
            return;
        }
        CNode* node = new CNode(val);
        node->next = cur->next;
        cur->next = node;
        if (cur == tail) tail = node; // if inserted after tail, new node becomes tail
        cout << val << " inserted after " << target << " in circular list.\n";
    }

    // insert before first occurrence of target
    void insertBefore(int target, int val) {
        if (!tail) {
            cout << "List empty. Cannot insert before " << target << ".\n";
            return;
        }

        CNode* head = tail->next;
        // if head is the target, just insert at beginning
        if (head->data == target) {
            insertAtBeginning(val);
            return;
        }

        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head && cur->data != target) {
            prev = cur;
            cur = cur->next;
        }

        if (cur == head) {
            cout << "Value " << target << " not found in circular list.\n";
            return;
        }
        // insert between prev and cur
        CNode* node = new CNode(val);
        prev->next = node;
        node->next = cur;
        cout << val << " inserted before " << target << " in circular list.\n";
    }

    // delete first occurrence of val
    void deleteValue(int val) {
        if (!tail) {
            cout << "Circular List is empty. Nothing to delete.\n";
            return;
        }
        CNode* head = tail->next;

        // single node case
        if (head == tail && head->data == val) {
            delete head;
            tail = nullptr;
            cout << val << " deleted; list is now empty.\n";
            return;
        }

        // If head is to be deleted
        if (head->data == val) {
            CNode* toDel = head;
            tail->next = head->next;
            delete toDel;
            cout << val << " deleted from beginning of circular list.\n";
            return;
        }

        // search for value
        CNode* prev = head;
        CNode* cur = head->next;
        while (cur != head && cur->data != val) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head) {
            cout << "Value " << val << " not found in circular list.\n";
            return;
        }

        prev->next = cur->next;
        if (cur == tail) tail = prev; // if tail deleted, move tail
        delete cur;
        cout << val << " deleted from circular list.\n";
    }

    // search value: returns 1-based position if found (starting at head), -1 if not
    int search(int val) const {
        if (!tail) return -1;
        CNode* cur = tail->next; // head
        int pos = 1;
        do {
            if (cur->data == val) return pos;
            cur = cur->next;
            ++pos;
        } while (cur != tail->next);
        return -1;
    }

    // cleanup destructor
    ~CircularList() {
        if (!tail) return;
        CNode* head = tail->next;
        tail->next = nullptr; // break circle
        CNode* cur = head;
        while (cur) {
            CNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        tail = nullptr;
    }
};

/* ===========================
   Doubly Linked List
   Nodes: int data, prev, next
   Keep head pointer
   ============================ */

struct DNode {
    int data;
    DNode* prev;
    DNode* next;
    DNode(int d) : data(d), prev(nullptr), next(nullptr) {}
};

class DoublyList {
private:
    DNode* head;
public:
    DoublyList() : head(nullptr) {}

    bool isEmpty() const { return head == nullptr; }

    void display() const {
        if (!head) {
            cout << "Doubly List is empty.\n";
            return;
        }
        cout << "Doubly List (head->tail): ";
        DNode* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << "\n";
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        DNode* node = new DNode(val);
        node->next = head;
        if (head) head->prev = node;
        head = node;
        cout << val << " inserted at beginning of doubly list.\n";
    }

    // Insert at end
    void insertAtEnd(int val) {
        DNode* node = new DNode(val);
        if (!head) {
            head = node;
            cout << val << " inserted as the only node in doubly list.\n";
            return;
        }
        DNode* cur = head;
        while (cur->next) cur = cur->next;
        cur->next = node;
        node->prev = cur;
        cout << val << " inserted at end of doubly list.\n";
    }

    // Insert after first occurrence of target
    void insertAfter(int target, int val) {
        DNode* cur = head;
        while (cur && cur->data != target) cur = cur->next;
        if (!cur) {
            cout << "Value " << target << " not found in doubly list.\n";
            return;
        }
        DNode* node = new DNode(val);
        node->next = cur->next;
        node->prev = cur;
        if (cur->next) cur->next->prev = node;
        cur->next = node;
        cout << val << " inserted after " << target << " in doubly list.\n";
    }

    // Insert before first occurrence of target
    void insertBefore(int target, int val) {
        DNode* cur = head;
        while (cur && cur->data != target) cur = cur->next;
        if (!cur) {
            cout << "Value " << target << " not found in doubly list.\n";
            return;
        }
        DNode* node = new DNode(val);
        node->next = cur;
        node->prev = cur->prev;
        if (cur->prev) cur->prev->next = node;
        cur->prev = node;
        if (cur == head) head = node;
        cout << val << " inserted before " << target << " in doubly list.\n";
    }

    // Delete first occurrence of val
    void deleteValue(int val) {
        if (!head) {
            cout << "Doubly List is empty. Nothing to delete.\n";
            return;
        }
        DNode* cur = head;
        while (cur && cur->data != val) cur = cur->next;
        if (!cur) {
            cout << "Value " << val << " not found in doubly list.\n";
            return;
        }
        if (cur->prev) cur->prev->next = cur->next;
        else head = cur->next; // deleting head
        if (cur->next) cur->next->prev = cur->prev;
        delete cur;
        cout << val << " deleted from doubly list.\n";
    }

    // Search returns 1-based index from head, -1 if not found
    int search(int val) const {
        DNode* cur = head;
        int pos = 1;
        while (cur) {
            if (cur->data == val) return pos;
            cur = cur->next;
            ++pos;
        }
        return -1;
    }

    // destructor
    ~DoublyList() {
        DNode* cur = head;
        while (cur) {
            DNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        head = nullptr;
    }
};

/* ===========================
   Menu system
   ============================ */

void circularMenu(CircularList &cl) {
    int ch;
    do {
        cout << "\n--- Circular List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert AFTER a value\n";
        cout << "4. Insert BEFORE a value\n";
        cout << "5. Delete a value\n";
        cout << "6. Search for a value\n";
        cout << "7. Display list\n";
        cout << "8. Back to main\n";
        cout << "Enter choice: ";
        cin >> ch;

        int val, target;
        switch (ch) {
            case 1:
                cout << "Value to insert at beginning: "; cin >> val;
                cl.insertAtBeginning(val); break;
            case 2:
                cout << "Value to insert at end: "; cin >> val;
                cl.insertAtEnd(val); break;
            case 3:
                cout << "Target value (insert after): "; cin >> target;
                cout << "New value: "; cin >> val;
                cl.insertAfter(target, val); break;
            case 4:
                cout << "Target value (insert before): "; cin >> target;
                cout << "New value: "; cin >> val;
                cl.insertBefore(target, val); break;
            case 5:
                cout << "Value to delete: "; cin >> val;
                cl.deleteValue(val); break;
            case 6:
                cout << "Value to search: "; cin >> val;
                {
                    int pos = cl.search(val);
                    if (pos == -1) cout << val << " not found in circular list.\n";
                    else cout << val << " found at position " << pos << " from head.\n";
                }
                break;
            case 7:
                cl.display(); break;
            case 8:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 8);
}

void doublyMenu(DoublyList &dl) {
    int ch;
    do {
        cout << "\n--- Doubly List Menu ---\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert AFTER a value\n";
        cout << "4. Insert BEFORE a value\n";
        cout << "5. Delete a value\n";
        cout << "6. Search for a value\n";
        cout << "7. Display list\n";
        cout << "8. Back to main\n";
        cout << "Enter choice: ";
        cin >> ch;

        int val, target;
        switch (ch) {
            case 1:
                cout << "Value to insert at beginning: "; cin >> val;
                dl.insertAtBeginning(val); break;
            case 2:
                cout << "Value to insert at end: "; cin >> val;
                dl.insertAtEnd(val); break;
            case 3:
                cout << "Target value (insert after): "; cin >> target;
                cout << "New value: "; cin >> val;
                dl.insertAfter(target, val); break;
            case 4:
                cout << "Target value (insert before): "; cin >> target;
                cout << "New value: "; cin >> val;
                dl.insertBefore(target, val); break;
            case 5:
                cout << "Value to delete: "; cin >> val;
                dl.deleteValue(val); break;
            case 6:
                cout << "Value to search: "; cin >> val;
                {
                    int pos = dl.search(val);
                    if (pos == -1) cout << val << " not found in doubly list.\n";
                    else cout << val << " found at position " << pos << " from head.\n";
                }
                break;
            case 7:
                dl.display(); break;
            case 8:
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (ch != 8);
}

int main() {
    CircularList cl;
    DoublyList dl;
    int mainChoice;

    cout << "Circular & Doubly Linked Lists - Menu Driven Program\n";
    do {
        cout << "\n=== Main Menu ===\n";
        cout << "1. Operate on Circular Singly Linked List\n";
        cout << "2. Operate on Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1:
                circularMenu(cl);
                break;
            case 2:
                doublyMenu(dl);
                break;
            case 3:
                cout << "Exiting program.\n"; break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}
