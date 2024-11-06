#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<string> strs;
        for (int& x : nums) {
            string str = "";
            for (char c : to_string(x)) { str += to_string(mapping[c - '0']); }
            strs.push_back(str);
        }
        vector<pair<int, int>> both;
        for (int i = 0; i < strs.size(); i++) { both.push_back({stoi(strs[i]), i}); }
        sort(both.begin(), both.end());
        vector<int> ans;
        for (int i = 0; i < strs.size(); i++) { ans.push_back(nums[both[i].second]); }
        return ans;
    }
};
