#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        nums.insert(nums.begin(), INT_MAX - 5);
        int r = 1, count = 0;
        vector<int> ans;
        for (int l = 1; l < nums.size(); l++) {
            while (r - l + 1 < k) {
                r++;
                if (r == nums.size()) { return ans; }
                count += nums[r] == nums[r - 1] + 1;
            }
            ans.push_back(((count - (nums[l - 1] + 1 == nums[l])) == k - 1) ? nums[r] : -1);
            count -= nums[l] == nums[l - 1] + 1;
        }
        return ans;
    }
};
