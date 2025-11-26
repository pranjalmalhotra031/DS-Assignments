//  Given an integer n, return all the structurally unique BST's (binary search trees), which 
// has exactly n nodes of unique values from 1 to n. Return the answer in any order. 
// Example 1: 
// Input: n = 3 
// Output: [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]] 
// Example 2: 
// Input: n = 1 
// Output: [[1]] 
// Constraints: 
// 1 <= n <= 8 

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int v): val(v), left(nullptr), right(nullptr) {}
};

vector<TreeNode*> generate(int lo, int hi) {
    vector<TreeNode*> res;
    if (lo > hi) {
        res.push_back(nullptr);
        return res;
    }
    for (int rootVal = lo; rootVal <= hi; ++rootVal) {
        vector<TreeNode*> leftTrees = generate(lo, rootVal - 1);
        vector<TreeNode*> rightTrees = generate(rootVal + 1, hi);
        for (auto L : leftTrees) {
            for (auto R : rightTrees) {
                TreeNode* root = new TreeNode(rootVal);
                root->left = L;
                root->right = R;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<vector<string>> serialize_forest(const vector<TreeNode*>& trees) {
    vector<vector<string>> out;
    for (auto root : trees) {
        vector<string> vals;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front(); q.pop();
            if (!node) {
                vals.push_back("null");
                continue;
            }
            vals.push_back(to_string(node->val));
            q.push(node->left);
            q.push(node->right);
        }
        // trim trailing "null"s
        while (!vals.empty() && vals.back() == "null") vals.pop_back();
        out.push_back(vals);
    }
    return out;
}

// driver: reads single integer n and prints each tree serialization on its own line
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<TreeNode*> trees = generate(1, n);
    auto serialized = serialize_forest(trees);
    for (auto &vec : serialized) {
        cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            if (i) cout << ",";
            cout << vec[i];
        }
        cout << "]\n";
    }
    return 0;
}
