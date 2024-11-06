#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool detectCycle(int curr, vector<bool>& visited, vector<bool>& currVisited, map<int, vector<int>>& adjList) {
        if (!visited[curr]) {
            visited[curr] = true;
            currVisited[curr] = true;
            for (int& adj : adjList[curr]) {
                if (!visited[adj] && detectCycle(adj, visited, currVisited, adjList)) { return true; }
                else if (currVisited[adj]) { return true; }
            }
        }
        currVisited[curr] = false;
        return false;
    }

    void dfs(int curr, vector<bool>& visited, map<int, vector<int>>& adjList, vector<int>& ans) {
        if (visited[curr]) { return; }
        visited[curr] = true;
        for (int& adj : adjList[curr]) {
            dfs(adj, visited, adjList, ans);
        }
        ans.push_back(curr);
    }

    void fillAns(vector<int>& ans, int k) {
        vector<bool> usedDigits(k, false);
        for (int i = 0; i < ans.size(); i++) { usedDigits[ans[i] - 1] = true; }
        for (int i = 0; i < k; i++) { if (!usedDigits[i]) { ans.push_back(i + 1); } }
    }

public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        cin.tie(0)->sync_with_stdio(0);
        map<int, vector<int>> adjRow, adjCol;
        for (auto& x : rowConditions) { adjRow[x[0]].push_back(x[1]); }
        for (auto& x : colConditions) { adjCol[x[0]].push_back(x[1]); }

        vector<bool> visited(k + 1, false), currVisited(k + 1, false);
        for (int i = 1; i <= k; i++) {
            if (detectCycle(i, visited, currVisited, adjRow)) { return vector<vector<int>>(); }
        }
        visited = vector<bool>(k + 1, false), currVisited = vector<bool>(k + 1, false);
        for (int i = 1; i <= k; i++) {
            if (detectCycle(i, visited, currVisited, adjCol)) { return vector<vector<int>>(); }
        }

        visited = vector<bool>(k + 1, false);
        vector<int> ans1, ans2;
        for (auto& x : adjRow) { dfs(x.first, visited, adjRow, ans1); }
        reverse(ans1.begin(), ans1.end());
        fillAns(ans1, k);
        visited = vector<bool>(k + 1, false);
        for (auto& x : adjCol) { dfs(x.first, visited, adjCol, ans2); }
        reverse(ans2.begin(), ans2.end());
        fillAns(ans2, k);

        vector<pair<int, int>> coords(k, {-1, -1});
        int x = 0, y = 0;
        for (int i = 0; i < ans1.size(); i++) { coords[ans1[i] - 1] = {x++, -1}; }
        for (int i = 0; i < ans1.size(); i++) {
            if (coords[ans1[i] - 1].first == -1) { coords[ans1[i] - 1] = {x++, -1}; }
        }
        for (int i = 0; i < ans2.size(); i++) { coords[ans2[i] - 1] = {coords[ans2[i] - 1].first, y++}; }
        for (int i = 0; i < ans2.size(); i++) {
            if (coords[ans2[i] - 1].second == -1) { coords[ans2[i] - 1] = {coords[ans2[i] - 1].first, y++}; }
        }

        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) { ans[coords[i].first][coords[i].second] = i + 1; }
        return ans;
    }
};
