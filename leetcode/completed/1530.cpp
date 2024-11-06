#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        map<TreeNode*, vector<TreeNode*>> adj;
        queue<TreeNode*> curr, leaves;
        curr.push(root);
        while (!curr.empty()) {
            TreeNode* node = curr.front();
            curr.pop();
            if (node->left != nullptr) {
                adj[node->left].push_back(node);
                adj[node].push_back(node->left);
                curr.push(node->left);
            }
            if (node->right != nullptr) {
                adj[node->right].push_back(node);
                adj[node].push_back(node->right);
                curr.push(node->right);
            }
            if (node->left == nullptr && node->right == nullptr) { leaves.push(node); }
        }
        int ans = 0;
        while (!leaves.empty()) {
            TreeNode* leaf = leaves.front();
            leaves.pop();
            vector<TreeNode*> curr;
            set<TreeNode*> visited;
            curr.push_back(leaf);
            for (int i = 0; i < distance; i++) {
                vector<TreeNode*> next;
                for (TreeNode* node : curr) {
                    for (TreeNode* n : adj[node]) {
                        if (visited.find(n) == visited.end()) {
                            next.push_back(n);
                            visited.insert(n);
                            if (n->left == nullptr && n->right == nullptr) { ans++; }
                        }
                    }
                }
                curr = next;
            }
        }
        return ans / 2;
    }
};