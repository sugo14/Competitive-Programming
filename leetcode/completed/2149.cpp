#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> v1, v2, ans;
        for (int e : nums) {
            if (e > 0) {
                v1.push_back(e);
            } else {
                v2.push_back(e);
            }
        }
        for (int i = 0; i < v1.size(); i++) {
            ans.push_back(v1[i]);
            ans.push_back(v2[i]);
        }
        return ans;
    }
};
