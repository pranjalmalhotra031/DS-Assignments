//  Write a non-recursive function to traverse a BST in in-order traversal using stack.

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int val) {
    if (!root) return new Node(val);
    if (val < root->data) root->left = insert(root->left, val);
    else if (val > root->data) root->right = insert(root->right, val);
    return root; // ignore duplicates
}

void inorderIterative(Node* root) {
    stack<Node*> st;
    Node* curr = root;

    while (curr != nullptr || !st.empty()) {
        // push all left nodes
        while (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        }

        // get top element (do NOT use pop()'s return — pop() returns void)
        curr = st.top();
        st.pop();

        // visit
        cout << curr->data << " ";

        // go to right subtree
        curr = curr->right;
    }
}

int main() {
    Node* root = nullptr;
    int vals[] = {20, 10, 30, 5, 15, 25, 40};
    for (int v : vals) root = insert(root, v);

    cout << "Inorder (iterative): ";
    inorderIterative(root);
    cout << "\n";
    return 0;
}
