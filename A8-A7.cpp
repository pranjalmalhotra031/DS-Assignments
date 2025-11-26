// Write a program to merge two BSTs into a doubly-linked list in sorted order. 

#include <iostream>
#include <stack>
using namespace std;

// Binary tree node (BST)
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Doubly linked list node
struct DNode {
    int val;
    DNode *prev, *next;
    DNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

// push left descendants of node onto stack
void pushLefts(TreeNode* node, stack<TreeNode*>& st) {
    while (node) {
        st.push(node);
        node = node->left;
    }
}

// Merge two BSTs (root1, root2) into a sorted doubly-linked list.
// Returns head of the created DLL (or nullptr if both trees empty).
DNode* mergeBSTsToDLL(TreeNode* root1, TreeNode* root2) {
    stack<TreeNode*> s1, s2;
    pushLefts(root1, s1);
    pushLefts(root2, s2);

    DNode* head = nullptr;
    DNode* tail = nullptr;

    auto appendValue = [&](int v) {
        DNode* node = new DNode(v);
        if (!head) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    };

    // Traverse both trees in-order simultaneously
    while (!s1.empty() || !s2.empty()) {
        if (s1.empty()) {
            // take from s2
            TreeNode* t = s2.top(); s2.pop();
            appendValue(t->val);
            pushLefts(t->right, s2);
        } else if (s2.empty()) {
            // take from s1
            TreeNode* t = s1.top(); s1.pop();
            appendValue(t->val);
            pushLefts(t->right, s1);
        } else {
            // both non-empty: compare next values (tops)
            if (s1.top()->val <= s2.top()->val) {
                TreeNode* t = s1.top(); s1.pop();
                appendValue(t->val);
                pushLefts(t->right, s1);
            } else {
                TreeNode* t = s2.top(); s2.pop();
                appendValue(t->val);
                pushLefts(t->right, s2);
            }
        }
    }

    return head;
}

// insert into BST (no duplicates for simplicity)
TreeNode* insertBST(TreeNode* root, int key) {
    if (!root) return new TreeNode(key);
    if (key < root->val) root->left = insertBST(root->left, key);
    else if (key > root->val) root->right = insertBST(root->right, key);
    return root;
}

// Print the doubly-linked list forward and backward
void printDLL(DNode* head) {
    cout << "DLL forward: ";
    DNode* cur = head;
    DNode* tail = nullptr;
    while (cur) {
        cout << cur->val;
        tail = cur;
        cur = cur->next;
        if (cur) cout << " <-> ";
    }
    cout << "\n";
    cout << "DLL backward: ";
    cur = tail;
    while (cur) {
        cout << cur->val;
        cur = cur->prev;
        if (cur) cout << " <-> ";
    }
    cout << "\n";
}

// Free DLL nodes
void freeDLL(DNode* head) {
    while (head) {
        DNode* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    // Example BST 1: {1, 3, 5, 7}
    TreeNode* root1 = nullptr;
    root1 = insertBST(root1, 5);
    insertBST(root1, 3);
    insertBST(root1, 7);
    insertBST(root1, 1);

    // Example BST 2: {2, 4, 6, 8}
    TreeNode* root2 = nullptr;
    root2 = insertBST(root2, 6);
    insertBST(root2, 4);
    insertBST(root2, 8);
    insertBST(root2, 2);

    DNode* mergedHead = mergeBSTsToDLL(root1, root2);

    printDLL(mergedHead);

    freeDLL(mergedHead);

    return 0;
}
