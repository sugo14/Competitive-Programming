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
    int findBottomLeftValue(TreeNode* root) {
        vector<TreeNode*> curr = {root};
        int leftmost;
        while (!curr.empty()) {
            leftmost = curr[0]->val;
            vector<TreeNode*> next;
            for (auto node : curr) {
                if (node->left) { next.push_back(node->left); }
                if (node->right) { next.push_back(node->right); }
            }
            curr = next;
        }
        return leftmost;
    }
};
