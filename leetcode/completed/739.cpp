#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> tempOccurences = vector<int>(72, -1);
        vector<int> ans = {};
        for (int i = 0; i < temperatures.size(); i++) {
            int curr = temperatures[temperatures.size() - 1 - i] - 30;
            if (tempOccurences[curr] == -1) {
                ans.push_back(0);
            }
            else {
                ans.push_back(i - tempOccurences[curr]);
            }
            for (int j = 0; j < curr; j++) {
                tempOccurences[j] = i;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    auto s = Solution();
    vector<int> temperatures = {30, 40, 50, 60};
    auto ans = s.dailyTemperatures(temperatures);
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
