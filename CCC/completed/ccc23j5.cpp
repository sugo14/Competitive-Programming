#include <bits/stdc++.h>
using namespace std;

std::vector<std::vector<char>> board;
int h, w, ans = 0;
string word;

char boardAt(int x, int y) {
    if (
        x < 0 ||
        x >= w ||
        y < 0 ||
        y >= h
    ) {
        return '\0';
    }
    return board[y][x];
}
int search(int x, int y, string term, std::pair<int, int> dir = {0, 0}, bool canTurn = true) {
    if (boardAt(x, y) != term[0]) {
        // position does not continue word
        return 0;
    }
    if (term[0] == boardAt(x, y) && term.length() == 1) {
        // full word found
        return 1;
    }
    if (dir == std::pair<int, int>(0, 0)) {
        // initial: search in all directions
        int total = 0;
        for (int dX = -1; dX <= 1; dX++) {
            for (int dY = -1; dY <= 1; dY++) {
                if (dX == 0 && dY == 0) {
                    continue;
                }
                total += search(x + dX, y + dY, term.substr(1), std::pair<int, int>(dX, dY), canTurn);
            }
        }
        return total;
    }
    else {
        int total = 0;
        if (canTurn) {
            if (dir.first != 0 && dir.second != 0) {
                total += search(x + dir.first, y - dir.second, term.substr(1), {dir.first, -dir.second}, false);
                total += search(x - dir.first, y + dir.second, term.substr(1), {-dir.first, dir.second}, false);
                total += search(x - dir.first, y - dir.second, term.substr(1), {-dir.first, -dir.second}, false);
            }
            else if (dir.first != 0) {
                total += search(x - dir.first, y, term.substr(1), {-dir.first, 0}, false);
                total += search(x, y + dir.first, term.substr(1), {0, dir.first}, false);
                total += search(x, y - dir.first, term.substr(1), {0, -dir.first}, false);
            }
            else if (dir.second != 0) {
                total += search(x, y - dir.second, term.substr(1), {0, -dir.second}, false);
                total += search(x + dir.second, y, term.substr(1), {dir.second, 0}, false);
                total += search(x - dir.second, y, term.substr(1), {-dir.second, 0}, false);
            }
        }
        total += search(x + dir.first, y + dir.second, term.substr(1), dir, canTurn);
        return total;
    }
}

int main() {
    cin >> word >> h >> w;
    for (int i = 0; i < h; i++) {
        std::vector<char> row = {};
        for (int j = 0; j < w; j++) {
            char c;
            cin >> c;
            row.push_back(c);
        }
        board.push_back(row);
    }
    for (int x = 0; x < w; x++) {
        for (int y = 0; y < h; y++) {
            ans += search(x, y, word);
        }
    }
    cout << ans << endl;
    return 0;
}
