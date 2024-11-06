#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        map<int, int> thing;
        int left = 0, big = 0;
        for (int right = 0; right < nums.size(); right++) {
            thing[nums[right]]++;
            if (thing[nums[right]] > k) {
                while (nums[left] != nums[right]) {
                    thing[nums[left]]--;
                    left++;
                }
                thing[nums[left]]--;
                left++;
            }
            big = max(big, right - left + 1);
        }
        return big;
    }
};
