#include <bits/stdc++.h>
using namespace std;

// i can safely say this one is not overcomplicated for once
// even after realizing it was just recursion, it still took me too long
// to realize to use the for loop so that i get every subset starting from every element

class Solution {
    vector<int> nums;
    int ans = 0;

    void dfs(int curr, int i) {
        if (i == nums.size()) { ans += curr; return; }
        dfs(curr, i + 1);
        dfs(curr ^ nums[i], i + 1);
    }
public:
    int subsetXORSum(vector<int>& nums) {
        this->nums = nums;
        for (int i = 0; i < nums.size(); i++) { dfs(nums[i], i + 1); }
        return ans;
    }
};
