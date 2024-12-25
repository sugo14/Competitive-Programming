#include <bits/stdc++.h>
using namespace std;

// i finished 1 minute before next day LMAOOOO
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        for (auto edge : edges1) {
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for (auto edge : edges2) {
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }
        vector<int> curr = {0};
        vector<bool> vis(n, false);
        vis[0] = true;
        int last = 0;
        while (!curr.empty()) {
            last = curr[0];
            vector<int> next;
            for (auto node : curr) {
                for (auto nex : adj1[node]) {
                    if (!vis[nex]) {
                        vis[nex] = true;
                        next.push_back(nex);
                    }
                }
            }
            curr = next;
        }
        curr = {last};
        vis = vector<bool>(n, false);
        vis[last] = true;
        int ans1 = 0;
        while (!curr.empty()) {
            vector<int> next;
            for (auto node : curr) {
                for (auto nex : adj1[node]) {
                    if (!vis[nex]) {
                        vis[nex] = true;
                        next.push_back(nex);
                    }
                }
            }
            if (!next.empty()) { ans1++; }
            curr = next;
        }
        curr = {0};
        vis = vector<bool>(m, false);
        vis[0] = true;
        last = 0;
        while (!curr.empty()) {
            last = curr[0];
            vector<int> next;
            for (auto node : curr) {
                for (auto nex : adj2[node]) {
                    if (!vis[nex]) {
                        vis[nex] = true;
                        next.push_back(nex);
                    }
                }
            }
            curr = next;
        }
        curr = {last};
        vis = vector<bool>(m, false);
        vis[last] = true;
        int ans2 = 0;
        while (!curr.empty()) {
            vector<int> next;
            for (auto node : curr) {
                for (auto nex : adj2[node]) {
                    if (!vis[nex]) {
                        vis[nex] = true;
                        next.push_back(nex);
                    }
                }
            }
            if (!next.empty()) { ans2++; }
            curr = next;
        }
        return max(max(ans1, ans2), (ans1 + 1) / 2 + (ans2 + 1) / 2 + 1);
    }
};
