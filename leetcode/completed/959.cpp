#include <bits/stdc++.h>
using namespace std;

int n, m;
bool arr[93][93];

class Solution {
    void dfs(int i, int j) {
        if (arr[i][j]) { return; }
        arr[i][j] = true;
        if (i - 1 >= 0) { dfs(i - 1, j); }
        if (i + 1 < n) { dfs(i + 1, j); }
        if (j - 1 >= 0) { dfs(i, j - 1); }
        if (j + 1 < m) { dfs(i, j + 1); }
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        n = grid.size() * 3, m = grid[0].size() * 3;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int x = i * 3, y = j * 3;
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        arr[x + k][y + l] = false;
                    }
                }
                if (grid[i][j] == '\\') {
                    arr[x][y] = true;
                    arr[x + 1][y + 1] = true;
                    arr[x + 2][y + 2] = true;
                }
                else if (grid[i][j] == '/') {
                    arr[x][y + 2] = true;
                    arr[x + 1][y + 1] = true;
                    arr[x + 2][y] = true;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!arr[i][j]) {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};