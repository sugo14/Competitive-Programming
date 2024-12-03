#include <bits/stdc++.h>
using namespace std;

#define node pair<int, pair<int, int>>

class Solution {
    vector<vector<int>> dist;
    priority_queue<node, vector<node>, greater<node>> pq;
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid.size() > 1 && grid[0].size() > 1 && grid[0][1] > 1 && grid[1][0] > 1) { return -1; }
        int n = grid.size(), m = grid[0].size();
        dist = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        pq.push({0, {0, 0}});
        while (true) {
            node top = pq.top();
            pq.pop();
            int d = top.first, x = top.second.first, y = top.second.second;

            if (x == n - 1 && y == m - 1) { return d; }
            if (dist[x][y] != INT_MAX) { continue; }
            dist[x][y] = d;

            x--;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] > d) {
                    int difference = grid[x][y] - d;
                    pq.push({grid[x][y] + (difference % 2 == 0), {x, y}});
                }
                else {
                    pq.push({d + 1, {x, y}});
                }
            }
            x += 2;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] > d) {
                    int difference = grid[x][y] - d;
                    pq.push({grid[x][y] + (difference % 2 == 0), {x, y}});
                }
                else {
                    pq.push({d + 1, {x, y}});
                }
            }
            x--;
            y--;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] > d) {
                    int difference = grid[x][y] - d;
                    pq.push({grid[x][y] + (difference % 2 == 0), {x, y}});
                }
                else {
                    pq.push({d + 1, {x, y}});
                }
            }
            y += 2;
            if (x >= 0 && x < n && y >= 0 && y < m) {
                if (grid[x][y] > d) {
                    int difference = grid[x][y] - d;
                    pq.push({grid[x][y] + (difference % 2 == 0), {x, y}});
                }
                else {
                    pq.push({d + 1, {x, y}});
                }
            }
            y--;
        }
    }
};