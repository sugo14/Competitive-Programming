#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        vector<int> p = {nums[0]}, s = nums;
        for (int i = 1; i < nums.size(); i++) { p.push_back(max(p[i - 1], nums[i])); }
        for (int i = nums.size() - 2; i >= 0; i--) { s[i] = max(s[i + 1], nums[i]); }
        long long ans = 0;
        for (int i = 1; i < nums.size() - 1; i++) { ans = max(ans, (long long)(p[i - 1] - nums[i]) * (long long)s[i + 1]); }
        return ans;
    }
};
