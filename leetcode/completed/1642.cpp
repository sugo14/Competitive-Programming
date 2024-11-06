#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> biggest;
        unsigned long long biggestSum = 0;
        unsigned long long totalCost = 0;
        for (int i = 0; i < heights.size() - 1; i++) {
            int curr = heights[i];
            int next = heights[i + 1];
            if (curr >= next) {
                continue;
            }
            int diff = next - curr;
            totalCost += diff;
            if (biggest.size() < ladders) {
                biggestSum += diff;
                biggest.push(diff);
                continue;
            }
            else if (ladders > 0 && diff > biggest.top()) {
                biggestSum += diff;
                biggest.push(diff);
                biggestSum -= biggest.top();
                biggest.pop();
            }
            if (totalCost - biggestSum > bricks) {
                return i;
            }
        }
        return heights.size() - 1;
    }
};

int main() {
    vector<int> heights = {4, 2, 7, 6, 9, 14, 12};
    int bricks = 5;
    int ladders = 1;
    Solution sol;
    cout << sol.furthestBuilding(heights, bricks, ladders) << endl;
}
