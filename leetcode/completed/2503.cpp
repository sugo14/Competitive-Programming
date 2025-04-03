// not my greatest code

#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution {
    int values[1000005];
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> coords;
    vector<vector<int>> _grid;

    void p(int x, int y)
    {
        if (x < 0 || y < 0 || x >= _grid.size() || y >= _grid[0].size() || _grid[x][y] == -1) { return; }
        coords.push({_grid[x][y], {x, y}});
    }
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        fill(values, values + 1000005, 0);
        coords = priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>>();
        _grid = grid;

        p(0, 0);
        int cnt = 0;

        for (int i = 0; i < 1000000; i++) {
            while (!coords.empty() && coords.top().first < i) {
                pii pos = coords.top().second;
                coords.pop();
                if (_grid[pos.first][pos.second] == -1) { continue; }
                cnt++;
                _grid[pos.first][pos.second] = -1;
                p(pos.first - 1, pos.second);
                p(pos.first + 1, pos.second);
                p(pos.first, pos.second - 1);
                p(pos.first, pos.second + 1);
            }
            values[i] = cnt;
        }

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) { ans.push_back(values[queries[i]]); }
        return ans;
    }
};
