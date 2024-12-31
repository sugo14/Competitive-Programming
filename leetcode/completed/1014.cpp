#include <bits/stdc++.h>
using namespace std;

class Solution {
    int l[50001] = {INT_MIN}, r[50001] = {INT_MIN}, ans = 0;
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        for (int i = 0; i < values.size(); i++) { l[i] = max(values[i] + i, i == 0 ? INT_MIN : l[i - 1]); }
        for (int i = values.size() - 1; i >= 0; i--) { r[i] = max(values[i] - i, i == values.size() - 1 ? INT_MIN : r[i + 1]); }
        for (int i = 0; i < values.size() - 1; i++) { ans = max(ans, l[i] + r[i + 1]); }
        return ans;
    }
};
