#include <bits/stdc++.h>
using namespace std;

#define node pair<pair<int, int>, int>

struct compare {
    bool operator()(node a, node b) {
        return a.second > b.second;
    }
};

const int INF = 1e9;

class Solution {
    priority_queue<node, vector<node>, compare> q;
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        q.push({{0, 0}, (grid[0][0] == 1)});
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        while (true) {
            node p = q.top();
            q.pop();
            pair<int, int> pos = p.first;
            int cost = p.second;
            if (pos.first < 0 || pos.first >= n || pos.second < 0 || pos.second >= m) { continue; }
            if (dist[pos.first][pos.second] != INF) { continue; }

            cost += (grid[pos.first][pos.second] == 1);
            dist[pos.first][pos.second] = cost;
            if (pos == make_pair(n - 1, m - 1)) { return cost; }

            q.push({{pos.first + 1, pos.second}, cost});
            q.push({{pos.first - 1, pos.second}, cost});
            q.push({{pos.first, pos.second + 1}, cost});
            q.push({{pos.first, pos.second - 1}, cost});
        }
    }
};
