#include <bits/stdc++.h>
using namespace std;

int n, m, num;
map<int, vector<int>> adj;
vector<bool> vis;
set<int> pho;

pair<int, int> findFarthestAndDist(int start) {
    fill(vis.begin(), vis.end(), false);
    vis[start] = true;
    int dist = 0;
    vector<int> curr = {start};
    while (true) {
        dist++;
        vector<int> next;
        for (int x : curr) {
            for (int y : adj[x]) {
                if (vis[y]) { continue; }
                vis[y] = true;
                next.push_back(y);
            }
        }
        if (next.size() == 0) { break; }
        curr = next;
    }
    return {curr[0], dist};
}

vector<int> findLeaves() {
    fill(vis.begin(), vis.end(), false);
    vis[0] = true;
    int dist = 0;
    vector<int> curr = {0}, leaves;

    while (true) {
        dist++;
        vector<int> next;
        for (int x : curr) {
            if (adj[x].size() == 1 && pho.find(x) == pho.end()) { leaves.push_back(x); }
            for (int y : adj[x]) {
                if (vis[y]) { continue; }
                vis[y] = true;
                next.push_back(y);
            }
        }
        if (next.size() == 0) { break; }
        curr = next;
    }
    return leaves;
}

void prune(int leaf) {
    num--;
    int origLeaf = leaf;
    leaf = adj[leaf][0];
    adj[leaf].erase(find(adj[leaf].begin(), adj[leaf].end(), origLeaf));
    while (adj[leaf].size() == 1 && pho.find(leaf) == pho.end()) {
        num--;
        origLeaf = leaf;
        leaf = adj[leaf][0];
        adj[leaf].erase(find(adj[leaf].begin(), adj[leaf].end(), origLeaf));
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        pho.insert(x);
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    num = n;
    vis = vector<bool>(n, false);
    vector<int> leaves = findLeaves();
    for (int x : leaves) { prune(x); }
    int diameter = findFarthestAndDist(findFarthestAndDist(0).first).second;
    int ans = diameter + (num - diameter) * 2 - 1;
    cout << ans << endl;
}
