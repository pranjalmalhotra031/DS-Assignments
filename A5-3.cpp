// Write a program to find the middle of a linked list. 
// Input: 1->2->3->4->5 
// Output: 3 

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

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

    int findMiddle() {
        if (!head) {
            cout << "List is empty.\n";
            return -1;
        }

        Node* slow = head;
        Node* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow now points to the middle node
        return slow->data;
    }

    void display() {
        Node* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << "->";
            cur = cur->next;
        }
        cout << "\n";
    }
};

int main() {
    LinkedList list;

    // Sample input: 1->2->3->4->5
    int arr[] = {1,2,3,4,5};
    for (int x : arr) list.insert(x);

    cout << "Linked List: ";
    list.display();

    int middle = list.findMiddle();
    cout << "Middle Element: " << middle << endl;

    return 0;
}
