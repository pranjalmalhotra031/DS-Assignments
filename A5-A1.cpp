// Find the intersection node of two singly linked lists that merge into a Y-shaped structure. 
// The lists may vary in length and have distinct nodes at the beginning, but from the point of 
// intersection onward, they share the same sequence of nodes. The task is to identify the first 
// common node where the two lists converge. If the two linked lists have no intersection at all, 
// return null.   

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

// Two-pointer method to find intersection node (returns pointer to node or nullptr)
Node* getIntersectionNode(Node* headA, Node* headB) {
    if (!headA || !headB) return nullptr;

    Node* pA = headA;
    Node* pB = headB;

    // After at most m + n steps, either they'll meet at intersection or both become nullptr
    while (pA != pB) {
        pA = (pA ? pA->next : headB);
        pB = (pB ? pB->next : headA);
    }
    return pA; // either intersection node or nullptr
}

// Helper to print list from given head
void printList(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data;
        if (cur->next) cout << "->";
        cur = cur->next;
    }
    cout << endl;
}

int main() {
    // Build example lists that form a Y:
    // List A: 1->2->3\
    //                 -> 8->9->10
    // List B:      6->7/
    //
    // Intersection at node with value 8.

    // Shared tail
    Node* shared = new Node(8);
    shared->next = new Node(9);
    shared->next->next = new Node(10);

    // List A
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = new Node(3);
    headA->next->next->next = shared; // attach shared tail

    // List B
    Node* headB = new Node(6);
    headB->next = new Node(7);
    headB->next->next = shared; // attach same shared tail

    cout << "List A: ";
    printList(headA);
    cout << "List B: ";
    printList(headB);

    Node* intersect = getIntersectionNode(headA, headB);
    if (intersect) {
        cout << "Intersection at node with value: " << intersect->data << "\n";
    } else {
        cout << "No intersection (nullptr)\n";
    }
    
    return 0;
}
