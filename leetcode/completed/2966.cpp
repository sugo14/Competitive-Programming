#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        if (nums.size() % 3 != 0) {
            return {};
        }
        vector<vector<int>> ans = {};
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 3) {
            int upperBound = nums[i] + k;
            if (nums[i + 2] > upperBound) {
                return {};
            }
            ans.push_back({nums[i], nums[i + 1], nums[i + 2]});
        }
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<int> v = {1,3,3,2,7,3};
    auto ans = s.divideArray(v, 2);
    for (auto i : ans) {
        cout << "[ ";
        for (auto j : i) {
            cout << j << " ";
        }
        cout << "]" << endl;
    }
    cout << endl;
    return 0;
}
