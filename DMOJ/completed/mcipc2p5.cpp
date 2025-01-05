#include <bits/stdc++.h>
using namespace std;

// its so slow but its fine
// also spent many days debugging ull problem
// so thats why everything is ull now

#define ull unsigned long long

map<ull, vector<ull>> adj;
vector<ull> selfBuy;

map<ull, ull> memo;
ull dfs(ull node) {
    if (adj.find(node) == adj.end() || adj[node].size() == 0) {
        return 0;
    }
    if (memo.find(node) != memo.end()) {
        return memo[node];
    }
    ull ans = 0;
    for (ull i = 0; i < adj[node].size(); i++) {
        ans += dfs(adj[node][i]) + 1;
    }
    memo[node] = ans;
    return ans;
}

int main() {
    ull n, m, k;
    cin >> n >> m >> k;
    for (ull i = 0; i < n; i++) {
        ull x;
        cin >> x;
        selfBuy.push_back(x);
    }
    for (ull i = 0; i < m; i++) {
        ull x, y;
        cin >> x >> y;
        x--; y--;
        if (adj.find(x) == adj.end()) {
            adj[x] = {};
        }
        adj[x].push_back(y);
    }
    vector<ull> effect;
    ull ans = 0;
    for (ull i = 0; i < n; i++) {
        ull x = (ull) (dfs(i) + 1) * (ull) selfBuy[i];
        ans += x;
        effect.push_back(x);
    }
    sort(effect.begin(), effect.end(), greater<ull>());
    for (ull i = 0; i < k; i++) {
        ans -= effect[i];
    }
    cout << ans << endl;
}
