#include <bits/stdc++.h>
using namespace std;

// longer than it has to be

int n, m, r, c;
vector<vector<char>> grid;

int main() {
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
        vector<char> row;
        for (int j = 0; j < m; j++) {
            row.push_back('a' + ((i + j) % 3));
        }
        grid.push_back(row);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'd') {
            }
            grid[i][j] = 'd';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < c; j++) {
            grid[i][j] = 'd';
        }
    }
    if (r == n && c != m) {
        if (m % 2 == 0) {
            if (c % 2 == 1) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            int left = m / 2 - 1;
            int right = m / 2;
            int reps = (m - c) / 2;
            for (int i = 0; i < reps; i++) {
                for (int j = 0; j < n; j++) {
                    grid[j][left] = 'e' + (j % 3);
                    grid[j][right] = 'e' + (j % 3);
                }
                left--;
                right++;
            }
        }
        else {
            int x = m / 2;
            if (c % 2 == 0) {
                for (int i = 0; i < n; i++) {
                    grid[i][x] = 'e' + (i % 3);
                }
            }
            int left = m / 2 - 1;
            int right = m / 2 + 1;
            int reps = (m - c) / 2;
            for (int i = 0; i < reps; i++) {
                for (int j = 0; j < n; j++) {
                    grid[j][left] = 'e' + (j % 3);
                    grid[j][right] = 'e' + (j % 3);
                }
                left--;
                right++;
            }
        }
    }
    else if (c == m && r != n) {
        if (n % 2 == 0) {
            if (r % 2 == 1) {
                cout << "IMPOSSIBLE" << endl;
                return 0;
            }
            int top = n / 2 - 1;
            int bottom = n / 2;
            int reps = (n - r) / 2;
            for (int i = 0; i < reps; i++) {
                for (int j = 0; j < m; j++) {
                    grid[top][j] = 'e' + (j % 3);
                    grid[bottom][j] = 'e' + (j % 3);
                }
                top--;
                bottom++;
            }
        }
        else {
            int y = n / 2;
            if (r % 2 == 0) {
                for (int i = 0; i < m; i++) {
                    grid[y][i] = 'e' + (i % 3);
                }
            }
            int top = n / 2 - 1;
            int bottom = n / 2 + 1;
            int reps = (n - r) / 2;
            for (int i = 0; i < reps; i++) {
                for (int j = 0; j < m; j++) {
                    grid[top][j] = 'e' + (j % 3);
                    grid[bottom][j] = 'e' + (j % 3);
                }
                top--;
                bottom++;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}
