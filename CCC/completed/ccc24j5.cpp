#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> board;
int h, w;
pair<int, int> start;

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        vector<char> row;
        for (int i = 0; i < w; i++) {
            char c;
            cin >> c;
            row.push_back(c);
        }
        board.push_back(row);
    }
    cin >> start.first >> start.second; // r, c
    vector<pair<int, int>> curr = {start};
    set<pair<int, int>> visited = {};
    int ans = 0;
    while (curr.size() > 0) {
        vector<pair<int, int>> next;
        for (auto p : curr) {
            if (visited.find(p) != visited.end()) {
                continue;
            }
            visited.insert(p);
            char c = board[p.first][p.second];
            if (c == '*') {
                continue;
            }
            if (c == 'L') {
                ans += 10;
            }
            else if (c == 'M') {
                ans += 5;
            }
            else if (c == 'S') {
                ans += 1;
            }
            for (int x = 1; x >= -1; x--) {
                for (int y = 1; y >= -1; y--) {
                    if (x == 0 && y == 0 || x != 0 && y != 0) {
                        continue;
                    } 
                    pair<int, int> np = {p.first + x, p.second + y};
                    if (np.first < 0 || np.first >= h || np.second < 0 || np.second >= w) {
                        continue;
                    }
                    next.push_back({p.first + x, p.second + y});
                }
            }
        }
        curr = next;
    }
    std::cout << ans << endl;
    return 0;
}
