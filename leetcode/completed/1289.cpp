#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int small = INT_MAX, smallPos = -1, small2 = INT_MAX;
        for (int j = 0; j < m; j++) {
            if (small > grid[0][j]) {
                small2 = small;
                small = grid[0][j];
                smallPos = j;
            }
            else if (small2 > grid[0][j]) {
                small2 = grid[0][j];
            }
        }
        for (int i = 1; i < n; i++) {
            int newSmall = INT_MAX, newSmallPos = -1, newSmall2 = INT_MAX;
            for (int j = 0; j < m; j++) {
                int x = grid[i][j] + (smallPos == j ? small2 : small);
                if (newSmall > x) {
                    newSmall2 = newSmall;
                    newSmall = x;
                    newSmallPos = j;
                }
                else if (newSmall2 > x) {
                    newSmall2 = x;
                }
            }
            small = newSmall, smallPos = newSmallPos, small2 = newSmall2;
        }
        return small;
    }
};
