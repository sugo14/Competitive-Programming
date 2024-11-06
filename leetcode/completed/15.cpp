#include <bits/stdc++.h>
using namespace std;

// no longer so slow!!!

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        cin.tie(0)->sync_with_stdio(0);
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) { continue; }
            int l = i + 1, r = (int)nums.size() - 1;
            while (l < r) {
                if (l != i + 1 && nums[l] == nums[l - 1]) { l++; continue; }
                if (r != (int)nums.size() - 1 && nums[r] == nums[r + 1]) { r--; continue; }
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
                else if (sum < 0) { l++; }
                else { r--; }
            }
        }
        return ans;
    }
};
