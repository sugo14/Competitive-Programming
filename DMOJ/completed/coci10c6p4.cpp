#include <bits/stdc++.h>
using namespace std;

bool topsort(char curr, map<char, vector<char>> &adj, vector<bool> &visited, vector<bool>& currVisited, string& ans) {
    visited[curr - 'a'] = true;
    currVisited[curr - 'a'] = true;
    bool b = true;
    for (char c : adj[curr]) {
        if (currVisited[c - 'a']) { return false; }
        if (!visited[c - 'a']) { b = topsort(c, adj, visited, currVisited, ans); }
    }
    currVisited[curr - 'a'] = false;
    ans.push_back(curr);
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<string> v(n);
    map<char, vector<char>> adj;
    vector<bool> exist(26, false), visited(26, false), currVisited(26, false);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < v[i].size(); j++) { exist[v[i][j] - 'a'] = true; }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < min(v[i].size(), v[i - 1].size()); j++) {
            if (v[i][j] != v[i - 1][j]) {
                adj[v[i - 1][j]].push_back(v[i][j]);
                break;
            }
            if (j == v[i].size() - 1 && v[i - 1].size() > v[i].size()) {
                cout << "!" << endl;
                return 0;
            }
        }
    }
    string ans;
    for (int i = 0; i < 26; i++) {
        if (!exist[i] || visited[i]) { continue; }
        if (!topsort(i + 'a', adj, visited, currVisited, ans)) {
            cout << "!" << endl;
            return 0;
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 1; i < ans.size(); i++) {
        if (find(adj[ans[i - 1]].begin(), adj[ans[i - 1]].end(), ans[i]) == adj[ans[i - 1]].end()) {
            cout << "?" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
