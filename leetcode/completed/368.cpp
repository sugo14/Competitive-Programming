#include <bits/stdc++.h>
using namespace std;

// this is most likely overcomplicated with the last array but its fine

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1), last(nums.size(), -1), ans;
    
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    last[i] = j;
                }
            }
        }

        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (dp[i] > dp[curr]) { curr = i; }
        }
        while (curr != -1) {
            ans.push_back(nums[curr]);
            curr = last[curr];
        }
        return ans;
    }
};
    