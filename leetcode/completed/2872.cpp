#include <bits/stdc++.h>
using namespace std;

// i hate trees so bad
class Solution {
    vector<vector<int>> adj;
    vector<int> vals;
    long long k, root = -1, ans = 0;
    vector<bool> vis;

    long long dfs(long long curr) {
        long long x = 0;
        for (int& next : adj[curr]) {
            if (vis[next]) { continue; }
            vis[next] = true;
            long long nextSum = dfs(next);
            if (nextSum % k == 0) { ans++; }
            else { x += nextSum; }
        }
        x += vals[curr];
        return x;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        this->adj = vector<vector<int>>(n);
        for (vector<int>& edge : edges) {
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        this->vals = values;
        this->k = k;
        vis = vector<bool>(n, false);
        root = 0;
        dfs(root);
        return (ans == 0 ? 1 : ans);
    }
};
