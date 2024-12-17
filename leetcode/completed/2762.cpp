#include <bits/stdc++.h>
using namespace std;

class Solution {
    multiset<int> s;
    int r = 0;
    long long ans = 0;
public:
    long long continuousSubarrays(vector<int>& nums) {
        for (int l = 0; l < nums.size(); l++) {
            if (l > 0) { s.erase(s.find(nums[l - 1])); }
            while (r < nums.size() && (s.empty() || max(nums[r], *s.rbegin()) - min(nums[r], *s.begin()) <= 2)) { s.insert(nums[r++]); }
            ans += r - l;
        }
        return ans;
    }
};
