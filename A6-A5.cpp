// Given a 2D matrix, the task is to convert it into a doubly-linked list with four pointers 
// that are next, previous, up, and down, each node of this list should be connected to its 
// next, previous, up, and down nodes. 
// https://www.geeksforgeeks.org/construct-a-doubly-linked-linked-list-from-2d
// matrix/?ref=rp 

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Node {
    int data;
    Node *next; // right
    Node *prev; // left
    Node *up;   // above
    Node *down; // below
    Node(int v=0) : data(v), next(nullptr), prev(nullptr), up(nullptr), down(nullptr) {}
};

// Construct R x C grid of nodes from matrix; returns pointer to top-left node (or nullptr if empty)
Node* constructGrid(const vector<vector<int>>& mat) {
    int R = mat.size();
    if (R == 0) return nullptr;
    int C = mat[0].size();
    if (C == 0) return nullptr;

    // Create 2D array of Node*
    vector<vector<Node*>> nodes(R, vector<Node*>(C, nullptr));
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            nodes[i][j] = new Node(mat[i][j]);

    // Link pointers: next, prev, up, down
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (j + 1 < C) nodes[i][j]->next = nodes[i][j+1];
            if (j - 1 >= 0) nodes[i][j]->prev = nodes[i][j-1];
            if (i - 1 >= 0) nodes[i][j]->up = nodes[i-1][j];
            if (i + 1 < R) nodes[i][j]->down = nodes[i+1][j];
        }
    }

    return nodes[0][0]; // top-left
}

// print each row by following next pointers starting from rowHead
void printRows(Node* topLeft, int rows, int cols) {
    cout << "Rows (using next pointers):\n";
    Node* row = topLeft;
    for (int r = 0; r < rows; ++r) {
        Node* cur = row;
        for (int c = 0; c < cols; ++c) {
            if (!cur) break;
            cout << cur->data;
            if (c+1 < cols) cout << " -> ";
            cur = cur->next;
        }
        cout << "\n";
        if (row) row = row->down; // go to next row's head
    }
}

// print each column by following down pointers starting from colHead
void printCols(Node* topLeft, int rows, int cols) {
    cout << "Columns (using down pointers):\n";
    Node* colHead = topLeft;
    for (int c = 0; c < cols; ++c) {
        Node* cur = colHead;
        for (int r = 0; r < rows; ++r) {
            if (!cur) break;
            cout << cur->data;
            if (r+1 < rows) cout << " -> ";
            cur = cur->down;
        }
        cout << "\n";
        if (colHead) colHead = colHead->next; // go to next column's head
    }
}

// print neighbors of each node (for debugging/verification)
void printNeighbors(Node* topLeft, int rows, int cols) {
    cout << "\nNode neighbors (format: node : prev, next, up, down)\n";
    Node* row = topLeft;
    for (int r = 0; r < rows; ++r) {
        Node* cur = row;
        for (int c = 0; c < cols; ++c) {
            if (!cur) break;
            cout << setw(3) << cur->data << " : ";
            if (cur->prev) cout << cur->prev->data; else cout << "NULL";
            cout << ", ";
            if (cur->next) cout << cur->next->data; else cout << "NULL";
            cout << ", ";
            if (cur->up) cout << cur->up->data; else cout << "NULL";
            cout << ", ";
            if (cur->down) cout << cur->down->data; else cout << "NULL";
            cout << "\n";
            cur = cur->next;
        }
        if (row) row = row->down;
    }
}

// Free all nodes (walk row by row)
void freeGrid(Node* topLeft, int rows, int cols) {
    // Break links and delete nodes row-wise to avoid double deletion
    Node* row = topLeft;
    for (int r = 0; r < rows && row; ++r) {
        Node* cur = row;
        Node* nextRowHead = row->down;
        for (int c = 0; c < cols && cur; ++c) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        row = nextRowHead;
    }
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {11, 12, 13, 14},
        {21, 22, 23, 24},
        {31, 32, 33, 34}
    };

    int R = mat.size();
    int C = (R > 0) ? mat[0].size() : 0;

    Node* topLeft = constructGrid(mat);
    if (!topLeft) {
        cout << "Empty matrix.\n";
        return 0;
    }

    // Demonstrations
    printRows(topLeft, R, C);
    cout << "\n";
    printCols(topLeft, R, C);
    printNeighbors(topLeft, R, C);

    freeGrid(topLeft, R, C);

    return 0;
}
