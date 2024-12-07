#include <bits/stdc++.h>
using namespace std;

// isnt this the quintessential binary search problem?

class Solution {
    int ops(vector<int>& nums, int maxVal) {
        int res = 0;
        for (int& x : nums) { res += x / maxVal + (x % maxVal == 0 ? 0 : 1) - 1; }
        return res;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = 1e9;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (ops(nums, mid) <= maxOperations) { high = mid; }
            else { low = mid + 1; }
        }
        return low;
    }
};
