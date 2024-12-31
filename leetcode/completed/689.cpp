#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> sums;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (i >= k) { currSum -= nums[i - k]; }
            if (i >= k - 1) { sums.push_back(currSum); }
        }
        vector<int> l(sums.size()), r(sums.size()), il(sums.size()), ir(sums.size());
        for (int i = 0; i < sums.size(); i++) {
            if (sums[i] > (i == 0 ? 0 : l[i - 1])) {
                l[i] = sums[i];
                il[i] = i;
            }
            else {
                l[i] = i == 0 ? 0 : l[i - 1];
                il[i] = i == 0 ? 0 : il[i - 1];
            }
        }
        for (int i = sums.size() - 1; i >= 0; i--) {
            if (sums[i] >= (i == sums.size() - 1 ? 0 : r[i + 1])) {
                r[i] = sums[i];
                ir[i] = i;
            }
            else {
                r[i] = i == sums.size() - 1 ? 0 : r[i + 1];
                ir[i] = i == sums.size() - 1 ? sums.size() - 1 : ir[i + 1];
            }
        }
        vector<int> ans;
        for (int i = k; i < sums.size() - k; i++) {
            if (ans.empty() || (sums[il[i - k]] + sums[i] + sums[ir[i + k]] > sums[il[ans[1] - k]] + sums[ans[1]] + sums[ir[ans[1] + k]])) { ans = {il[i - k], i, ir[i + k]}; }
        }
        for (int i = 0; i < l.size(); i++) {
            cout << l[i] << ' ' << il[i] << ' ' << r[i] << ' ' << ir[i] << '\n';
        }
        return ans;
    }
};
