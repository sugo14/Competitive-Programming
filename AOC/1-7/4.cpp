#include <bits/stdc++.h>
using namespace std;

struct pii {
    int x, y;
};

vector<string> grid;
string str = "XMAS";

bool findCnt(pii pos, pii dir, int i = 0) {
    if (i == str.size()) { return true; }
    if (pos.x < 0 || pos.y < 0 || pos.x >= grid.size() || pos.y >= grid[0].size()) { return false; }
    if (grid[pos.x][pos.y] != str[i]) { return false; }
    return findCnt({pos.x + dir.x, pos.y + dir.y}, dir, i + 1);
}

int startFindCnt(pii pos) {
    int cnt = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) { continue; }
            cnt += findCnt(pos, {dx, dy});
        }
    }
    return cnt;
}

int startFindCnt2(pii pos) {
    int cnt = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 || dy == 0) { continue; }
            cnt += findCnt({pos.x + dx, pos.y + dy}, {-dx, -dy}, 1);
        }
    }
    return cnt == 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    freopen("4.in", "r", stdin);
    string l, s;
    int ans = 0;
    while (getline(cin, l)) {
        if (l.empty() || l == "\n") continue;
        istringstream iss(l);
        iss >> s;
        grid.push_back(s);
    }

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            ans += startFindCnt2({i, j});
        }
    }
    cout << ans << '\n';
}
