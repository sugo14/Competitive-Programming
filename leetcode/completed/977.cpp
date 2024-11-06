#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        vector<int> v;
        v.resize(n);
        int l = 0, r = n - 1, i = n - 1;
        while (l < r) {
            if (nums[l] < nums[r]) {
                v[i] = nums[r];
                r--;
            }
            else {
                v[i] = nums[l];
                l++;
            }
            i--;
        }
        return v;
    }
};
