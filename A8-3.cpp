// Write a program for binary search tree (BST) having functions for the following 
// operations: 
// (a) Insert an element (no duplicates are allowed), 
// (b) Delete an existing element, 
// (c) Maximum depth of BST 
// (d) Minimum depth of  

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// ---------- (a) Insert (no duplicates) ----------
Node* insertNode(Node* root, int key) {
    if (!root) return new Node(key);

    if (key < root->key) {
        root->left = insertNode(root->left, key);
    } else if (key > root->key) {
        root->right = insertNode(root->right, key);
    } else {
        // duplicate — do nothing
        cout << "Key " << key << " already exists. Duplicates not allowed.\n";
    }
    return root;
}

// find minimum node in a subtree (used in deletion)
Node* findMinNode(Node* root) {
    if (!root) return nullptr;
    while (root->left) root = root->left;
    return root;
}

// ---------- (b) Delete an existing element ----------
Node* deleteNode(Node* root, int key) {
    if (!root) {
        cout << "Key " << key << " not found.\n";
        return nullptr;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        // Found node to delete
        if (!root->left && !root->right) {
            // leaf
            delete root;
            cout << "Deleted leaf node " << key << ".\n";
            return nullptr;
        } else if (!root->left) {
            // only right child
            Node* tmp = root->right;
            delete root;
            cout << "Deleted node " << key << " (had only right child).\n";
            return tmp;
        } else if (!root->right) {
            // only left child
            Node* tmp = root->left;
            delete root;
            cout << "Deleted node " << key << " (had only left child).\n";
            return tmp;
        } else {
            // two children: replace with inorder successor (min in right subtree)
            Node* succ = findMinNode(root->right);
            root->key = succ->key;
            root->right = deleteNode(root->right, succ->key);
            cout << "Deleted node " << key << " (replaced by inorder successor " << succ->key << ").\n";
        }
    }
    return root;
}

// ---------- (c) Maximum depth (height) ----------
// Height measured in nodes. For empty tree returns 0. For single node returns 1.
int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// ---------- (d) Minimum depth ----------
// Minimum number of nodes from root down to the nearest leaf
int minDepth(Node* root) {
    if (!root) return 0;
    // If one child is NULL, we should consider the other child only
    if (!root->left && !root->right) return 1;
    if (!root->left) return 1 + minDepth(root->right);
    if (!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

// Inorder traversal (sorted order) 
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

// Free tree nodes
void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    int choice = 0;

    cout << "BST Menu:\n";
    do {
        cout << "\n1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. In-order display\n";
        cout << "4. Maximum depth (height)\n";
        cout << "5. Minimum depth\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        if (choice == 1) {
            int x; cout << "Enter key to insert: "; cin >> x;
            root = insertNode(root, x);
        } else if (choice == 2) {
            int x; cout << "Enter key to delete: "; cin >> x;
            root = deleteNode(root, x);
        } else if (choice == 3) {
            cout << "BST (In-order): ";
            inorderPrint(root);
            cout << "\n";
        } else if (choice == 4) {
            cout << "Maximum depth (height) = " << maxDepth(root) << "\n";
        } else if (choice == 5) {
            cout << "Minimum depth = " << minDepth(root) << "\n";
        } else if (choice == 6) {
            cout << "Exiting...\n";
        } else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    freeTree(root);
    return 0;
}
