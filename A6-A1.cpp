// Given a Circular linked list. The task is split into two Circular Linked lists. If there are an 
// odd number of nodes in the given circular linked list then out of the resulting two halved 
// lists, the first list should have one node more than the second list.  
// https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/  
// Input:  10->4->9 
// Output: 10->4 , 9

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// print a circular list starting at head (prints single pass)
void printCircular(Node* head) {
    if (!head) {
        cout << "Empty\n";
        return;
    }
    Node* cur = head;
    do {
        cout << cur->data;
        cur = cur->next;
        if (cur != head) cout << " -> ";
    } while (cur != head);
    cout << "\n";
}

// Split circular linked list 'head' into two circular lists head1_ref and head2_ref.
// If odd number of nodes, first list gets the extra node.
void splitCircularList(Node* head, Node*& head1_ref, Node*& head2_ref) {
    head1_ref = nullptr;
    head2_ref = nullptr;

    if (!head) return;

    // If there's only one node, first list is head and second is NULL (could also set second=head)
    if (head->next == head) {
        head1_ref = head;
        head2_ref = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Move fast by 2 and slow by 1 until fast reaches last or second-last node
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // For even number of nodes, move fast to last node
    if (fast->next->next == head) {
        fast = fast->next;
    }

    // Now slow is end of first half, fast is last node of list
    head1_ref = head;
    head2_ref = slow->next;

    // Make first half circular
    slow->next = head1_ref;

    // Make second half circular
    fast->next = head2_ref;
}

int main() {
    // Build sample circular list: 10 -> 4 -> 9 -> back to 10
    Node* head = new Node(10);
    head->next = new Node(4);
    head->next->next = new Node(9);
    head->next->next->next = head; // make circular

    cout << "Original Circular List: ";
    printCircular(head);

    Node* head1 = nullptr;
    Node* head2 = nullptr;
    splitCircularList(head, head1, head2);

    cout << "First half:  ";
    printCircular(head1);
    cout << "Second half: ";
    printCircular(head2);

    return 0;
}
