#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 2; i < grid.size(); i++) {
            for (int j = 2; j < grid[0].size(); j++) {
                bool toSee[9] = {false, false, false, false, false, false, false, false, false};
                bool magic = true;
                for (int x = i - 2; x <= i; x++) {
                    for (int y = j - 2; y <= j; y++) {
                        if (grid[x][y] < 1 || grid[x][y] > 9) {
                            magic = false;
                            break;
                        }
                        toSee[grid[x][y] - 1] = true;
                    }
                    if (!magic) { break; }
                }
                for (int x = 0; x < 9; x++) {
                    if (!toSee[x]) {
                        magic = false;
                        break;
                    }
                }
                int sum = 0;
                for (int y = j - 2; y <= j; y++) { sum += grid[i - 2][y]; }
                for (int x = i - 1; x <= i; x++) {
                    int newSum = 0;
                    for (int y = j - 2; y <= j; y++) {
                        newSum += grid[x][y];
                    }
                    if (sum != newSum) {
                        magic = false;
                        break;
                    }
                }
                sum = 0;
                for (int x = i - 2; x <= i; x++) { sum += grid[x][j - 2]; }
                for (int y = j - 1; y <= j; y++) {
                    int newSum = 0;
                    for (int x = i - 2; x <= i; x++) {
                        newSum += grid[x][y];
                    }
                    if (sum != newSum) {
                        magic = false;
                        break;
                    }
                }
                sum = grid[i - 2][j - 2] + grid[i - 1][j - 1] + grid[i][j];
                if (sum != grid[i - 2][j] + grid[i - 1][j - 1] + grid[i][j - 2]) {
                    magic = false;
                }
                if (magic) { ans++; }
            }
        }
        return ans;
    }
};