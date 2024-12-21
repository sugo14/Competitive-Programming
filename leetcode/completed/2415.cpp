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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<TreeNode*> nodes = {root};
        int i = 1;
        while (true) {
            vector<TreeNode*> nextNodes;
            for (auto& node : nodes) {
                if (node->left == nullptr) { return root; }
                nextNodes.push_back(node->left);
                nextNodes.push_back(node->right);
            }
            if (i % 2 == 1) {
                for (int j = 0; j < nextNodes.size() / 2; j++) {
                    swap(nextNodes[j]->val, nextNodes[nextNodes.size() - j - 1]->val);
                }
            }
            nodes = nextNodes;
            i++;
        }
    }
};
