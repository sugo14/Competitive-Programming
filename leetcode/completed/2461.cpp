#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
    int cnt[100005], currSum = 0, multiples = 0, ans = 0;
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        for (int r = 0; r < nums.size(); r++) {
            cnt[nums[r]]++;
            currSum += nums[r];
            if (cnt[nums[r]] > 1) { multiples++; }
            if (multiples == 0) { ans = max(ans, currSum); }
            if (r - k + 1 < 0) { continue; }
            cnt[nums[r - k + 1]]--;
            currSum -= nums[r - k + 1];
            if (cnt[nums[r - k + 1]] > 0) { multiples--; }
        }
        return ans;
    }
};
