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
    vector<int> diffs;
public:
    int minimumOperations(TreeNode* root) {
        diffs = vector<int>(1e5 + 1, 0);
        vector<TreeNode*> curr = {root};
        int ans = 0;

        while (!curr.empty()) {
            vector<TreeNode*> next;
            for (auto node : curr) {
                if (node->left) { next.push_back(node->left); }
                if (node->right) { next.push_back(node->right); }
            }

            vector<int> vals, sorted;
            for (auto node : curr) { vals.push_back(node->val); }
            sorted = vals;
            sort(sorted.begin(), sorted.end());

            for (int i = 0; i < vals.size(); i++) {
                if (vals[i] != sorted[i]) {
                    diffs[vals[i]] = i;
                }
            }

            for (int i = 0; i < vals.size(); i++) {
                if (vals[i] != sorted[i]) {
                    swap(vals[i], vals[diffs[sorted[i]]]);
                    int a = i, b = diffs[sorted[i]];
                    if (vals[a] != sorted[a]) { diffs[vals[a]] = a; }
                    if (vals[b] != sorted[b]) { diffs[vals[b]] = b; }
                    ans++;
                }
            }
            curr = next;
        }
        return ans;
    }
};
