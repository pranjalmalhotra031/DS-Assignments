// Write a program to check if a doubly linked list of characters is palindrome or not. 

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

struct DNode {
    char data;
    DNode* prev;
    DNode* next;
    DNode(char c) : data(c), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedCharList {
public:
    DNode* head;
    DNode* tail;
    DoublyLinkedCharList() : head(nullptr), tail(nullptr) {}

    // Append a character to the end of the list
    void append(char c) {
        DNode* node = new DNode(c);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }

    // Build list from a string.
    // If normalize=true: include only alphanumeric chars and convert to lower-case.
    // If normalize=false: include every character as-is.
    void buildFromString(const string &s, bool normalize = true) {
        for (char ch : s) {
            if (normalize) {
                if (!isalnum(static_cast<unsigned char>(ch))) continue;
                append(static_cast<char>(tolower(static_cast<unsigned char>(ch))));
            } else {
                append(ch);
            }
        }
    }

    // Check palindrome by two-pointer comparison from head and tail.
    bool isPalindrome() const {
        DNode* left = head;
        DNode* right = tail;
        while (left && right && left != right && left->prev != right) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->prev;
        }
        return true;
    }

    // Display list (for debugging)
    void display() const {
        DNode* cur = head;
        while (cur) {
            cout << cur->data;
            if (cur->next) cout << " <-> ";
            cur = cur->next;
        }
        cout << "\n";
    }

    // Free nodes
    ~DoublyLinkedCharList() {
        DNode* cur = head;
        while (cur) {
            DNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
};

int main() {
    cout << "Enter a string to check (press Enter):\n";
    string line;
    getline(cin, line);

    // Build normalized list (ignore non-alphanumeric, case-insensitive)
    DoublyLinkedCharList list;
    list.buildFromString(line, true);

    cout << "Normalized list contents: ";
    list.display();

    if (list.isPalindrome()) {
        cout << "Result: The string is a palindrome (with normalization).\n";
    } else {
        cout << "Result: The string is NOT a palindrome (with normalization).\n";
    }

    return 0;
}
