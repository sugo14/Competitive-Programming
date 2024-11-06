#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans += 4 * grid[i][j] - ((i + 1 < grid.size() && grid[i][j]) ? 2 * grid[i + 1][j] : 0) - ((j + 1 < grid[0].size() && grid[i][j]) ? 2 * grid[i][j + 1] : 0);
            }
        }
        return ans;
    }
};
