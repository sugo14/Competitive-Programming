#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto wall : walls) { grid[wall[0]][wall[1]] = 2; }
        for (auto guard : guards) { grid[guard[0]][guard[1]] = 3; }
        for (int a = 0; a < m; a++) {
            for (int b = 0; b < n; b++) {
                int x = grid[a][b];
                if (x == 3) {
                    for (int i = a + 1; i < m; i++) {
                        if (grid[i][b] >= 2) { break; }
                        grid[i][b] = 1;
                    }
                    for (int i = a - 1; i >= 0; i--) {
                        if (grid[i][b] >= 2) { break; }
                        grid[i][b] = 1;
                    }
                    for (int i = b + 1; i < n; i++) {
                        if (grid[a][i] >= 2) { break; }
                        grid[a][i] = 1;
                    }
                    for (int i = b - 1; i >= 0; i--) {
                        if (grid[a][i] >= 2) { break; }
                        grid[a][i] = 1;
                    }
                }
            }
        }
        int unguarded = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) { unguarded++; }
            }
        }
        return unguarded;
    }
};
