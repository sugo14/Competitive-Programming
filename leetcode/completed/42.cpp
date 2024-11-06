#include <bits/stdc++.h>
using namespace std;

class Solution {
    int biggestLWall[20002], biggestRWall[20002];
public:
    int trap(vector<int>& height) {
        for (int i = 1; i < height.size(); i++) { biggestLWall[i] = max(biggestLWall[i - 1], height[i - 1]); }
        for (int i = height.size() - 2; i >= 0; i--) { biggestRWall[i] = max(biggestRWall[i + 1], height[i + 1]); }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) { ans += max(min(biggestLWall[i], biggestRWall[i]) - height[i], 0); }
        return ans;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution s;
    cout << s.trap(height) << endl;
    return 0;
}
