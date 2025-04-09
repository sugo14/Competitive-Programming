#include <bits/stdc++.h>
using namespace std;

// not proud of this one but the author of this problem shouldnt be proud of themselves either

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> s;
        vector<int> newNums;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (s.find(x) == s.end()) {
                newNums.push_back(x);
                s.insert(x);
            }
        }
        sort(newNums.begin(), newNums.end());
        if (newNums[0] < k) { return -1; }
        for (int i = newNums.size() - 1; i >= 0; i--) {
            if (newNums[i] == k) { return newNums.size() - i - 1; }
        }
        return newNums.size();
    }
};
    