// Implement following functions for Binary Search Trees  
// (a) Search a given item (Recursive & Non-Recursive) 
// (b) Maximum element of the BST  
// (c) Minimum element of the BST  
// (d) In-order successor of a given node the BST  
// (e) In-order predecessor of a given node the BST 

#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

// Insert key into BST (standard iterative insert)
Node* insert(Node* root, int key) {
    if (!root) return new Node(key);
    Node* cur = root;
    Node* parent = nullptr;
    while (cur) {
        parent = cur;
        if (key < cur->key) cur = cur->left;
        else if (key > cur->key) cur = cur->right;
        else return root; // duplicate: ignore
    }
    if (key < parent->key) parent->left = new Node(key);
    else parent->right = new Node(key);
    return root;
}

/* ---------- (a) Search ---------- */

// Recursive search
Node* searchRecursive(Node* root, int key) {
    if (!root) return nullptr;
    if (root->key == key) return root;
    if (key < root->key) return searchRecursive(root->left, key);
    else return searchRecursive(root->right, key);
}

// Iterative (non-recursive) search
Node* searchIterative(Node* root, int key) {
    Node* cur = root;
    while (cur) {
        if (cur->key == key) return cur;
        if (key < cur->key) cur = cur->left;
        else cur = cur->right;
    }
    return nullptr;
}

/* ---------- (b) Minimum & (c) Maximum ---------- */

Node* minimum(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->left) cur = cur->left;
    return cur;
}

Node* maximum(Node* root) {
    if (!root) return nullptr;
    Node* cur = root;
    while (cur->right) cur = cur->right;
    return cur;
}

/* ---------- (d) In-order Successor ----------
// Return node pointer to successor of given key (nullptr if none or key not found)
   Approach:
   - Find node with key (iterative).
   - If node has right child: successor = minimum(node->right).
   - Else: traverse from root, keep successor candidate: 
       when moving left (root->key > key) set candidate=root; move left.
       when moving right, move right.
*/
Node* inorderSuccessorByKey(Node* root, int key) {
    // First find node
    Node* target = root;
    while (target && target->key != key) {
        if (key < target->key) target = target->left;
        else target = target->right;
    }
    if (!target) return nullptr; // key not found

    // Case 1: right subtree exists
    if (target->right) return minimum(target->right);

    // Case 2: no right subtree - walk from root to find successor
    Node* succ = nullptr;
    Node* cur = root;
    while (cur) {
        if (key < cur->key) {
            succ = cur;
            cur = cur->left;
        } else if (key > cur->key) {
            cur = cur->right;
        } else break; // reached target
    }
    return succ;
}

/* ---------- (e) In-order Predecessor ----------
// Symmetric of successor
*/
Node* inorderPredecessorByKey(Node* root, int key) {
    // Find node
    Node* target = root;
    while (target && target->key != key) {
        if (key < target->key) target = target->left;
        else target = target->right;
    }
    if (!target) return nullptr;

    // If left subtree exists, predecessor is maximum(left)
    if (target->left) return maximum(target->left);

    // Else walk from root, keep candidate predecessor
    Node* pred = nullptr;
    Node* cur = root;
    while (cur) {
        if (key > cur->key) {
            pred = cur;
            cur = cur->right;
        } else if (key < cur->key) {
            cur = cur->left;
        } else break;
    }
    return pred;
}

/* ---------- Print BST inorder (for verification) ---------- */
void inorderPrint(Node* root) {
    if (!root) return;
    inorderPrint(root->left);
    cout << root->key << " ";
    inorderPrint(root->right);
}

int main() {
    // Build sample BST
    // Insert keys: 20, 8, 22, 4, 12, 10, 14
    int keys[] = {20, 8, 22, 4, 12, 10, 14};
    Node* root = nullptr;
    for (int k : keys) root = insert(root, k);

    cout << "BST inorder: ";
    inorderPrint(root);
    cout << "\n\n";

    int q[] = {20, 8, 22, 4, 12, 10, 14, 100};
    for (int key : q) {
        Node* rrec = searchRecursive(root, key);
        Node* ritr = searchIterative(root, key);
        cout << "Search key " << key 
             << ": recursive=" << (rrec ? "Found" : "NotFound")
             << ", iterative=" << (ritr ? "Found" : "NotFound") << "\n";

        Node* succ = inorderSuccessorByKey(root, key);
        if (succ) cout << "  Successor of " << key << " = " << succ->key << "\n";
        else cout << "  Successor of " << key << " = NULL\n";

        Node* pred = inorderPredecessorByKey(root, key);
        if (pred) cout << "  Predecessor of " << key << " = " << pred->key << "\n";
        else cout << "  Predecessor of " << key << " = NULL\n";

        cout << "\n";
    }

    // min / max of whole tree
    Node* mn = minimum(root);
    Node* mx = maximum(root);
    cout << "Minimum in BST = " << (mn ? mn->key : -1) << "\n";
    cout << "Maximum in BST = " << (mx ? mx->key : -1) << "\n";

    return 0;
}
