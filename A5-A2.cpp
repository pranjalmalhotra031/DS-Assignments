// Given a linked list and a positive number K, reverse the nodes in groups of K. All the remaining 
// nodes after multiples of k should be left as it is. 

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
        if (!head)
            head = node;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = node;
        }
    }

    // Reverse K nodes and return new head of this segment
    Node* reverseK(Node* head, int K) {
        Node* cur = head;
        Node* prev = nullptr;
        Node* next = nullptr;
        int count = 0;

        // Check if we have at least K nodes
        Node* temp = head;
        int length = 0;
        while (temp && length < K) {
            temp = temp->next;
            length++;
        }
        if (length < K) return head; // fewer than K → leave as is

        // Reverse K nodes
        while (cur && count < K) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            count++;
        }

        // Recurrence: head now becomes last of this group
        if (next)
            head->next = reverseK(next, K);

        return prev; // new head of this k-group
    }

    void reverseInGroups(int K) {
        head = reverseK(head, K);
    }

    void display() {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << "->";
            cur = cur->next;
        }
        cout << "->NULL\n";
    }
};

int main() {
    LinkedList list;

    // Sample input: 1->2->3->4->5->6->7->8->NULL
    int arr[] = {1,2,3,4,5,6,7,8};
    for (int x : arr) list.insert(x);

    int K = 3;

    cout << "Original List: ";
    list.display();

    list.reverseInGroups(K);

    cout << "Reversed in groups of " << K << ": ";
    list.display();

    return 0;
}
