#include <bits/stdc++.h>
using namespace std;

int m, n, k, grid[30001][1001], difV[30001][1001];
int big, freq;

void setDifV(int x, int y, int h, int b) {
    if (x < 0 || x >= m || y < 0 || y >= n) { return; }
    int high = max(0, x - h), low = min(m, x + h + 1);
    difV[high][y] += b;
    difV[low][y] -= b;
}

void fillCircle(int x, int y, int b, int r) {
    for (int i = -r; i <= r; i++) {
        int h = sqrt(r * r - i * i);
        setDifV(x, y + i, h, b);
    }
}

void createGrid() {
    for (int i = 0; i < n; i++) {
        int currSum = 0;
        for (int j = 0; j < m; j++) {
            currSum += difV[j][i];
            grid[j][i] = currSum;
        }
    }
}

int main() {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        int x, y, b, r;
        cin >> x >> y >> r >> b;
        x--; y--;
        fillCircle(y, x, b, r);
    }
    createGrid();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = grid[i][j];
            if (x > big) {
                big = x;
                freq = 1;
            }
            else if (x == big) {
                freq++;
            }
        }
    }
    cout << big << "\n" << freq << "\n";
    return 0;
}
