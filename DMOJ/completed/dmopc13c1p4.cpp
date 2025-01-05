#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int l, w;
        cin >> w >> l;
        vector<string> grid;
        grid.resize(l);
        pair<int, int> start = {-1, -1}, end = {-1, -1};
        for (int j = 0; j < l; j++) {
            cin >> grid[j];
            for (int k = 0; k < w; k++) {
                if (grid[j][k] == 'C') {
                    start = {j, k};
                }
                if (grid[j][k] == 'W') {
                    end = {j, k};
                }
            }
        }
        vector<pair<int, int>> curr = {start};
        int ans = 0;
        bool breakLoops = false;
        while (ans < 60) {
            vector<pair<int, int>> next;
            for (pair<int, int> e : curr) {
                if (e == end) {
                    cout << ans << endl;
                    breakLoops = true;
                    break;
                }
                if (e.first < 0 || e.first >= l || e.second < 0 || e.second >= w || grid[e.first][e.second] == 'X') {
                    continue;
                }
                grid[e.first][e.second] = 'X';
                next.push_back({e.first - 1, e.second});
                next.push_back({e.first + 1, e.second});
                next.push_back({e.first, e.second - 1});
                next.push_back({e.first, e.second + 1});
            }
            if (breakLoops) { break; }
            curr = next;
            ans++;
        }
        if (!breakLoops) { cout << "#notworth" << endl; }
    }
}
