#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int last = nums[0], currNum = 0;
        pair<int, int> maj = {nums[0], 1}; // {num, count}
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != last) {
                if (currNum > maj.second) {
                    maj.first = nums[i - 1];
                    maj.second = currNum;
                }
                currNum = 0;
            }
            currNum++;
            last = nums[i];
        }
        if (currNum > maj.second) {
            return nums[nums.size() - 1];
        }
        return maj.first;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = { 3, 3, 4 };
    int ans = sol.majorityElement(nums);
    cout << ans << endl;
}
