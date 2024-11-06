#include <bits/stdc++.h>
using namespace std;

int n;
int grid[101][101];
int temp[101][101];

void rotate() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            temp[j][n - 1 - i] = grid[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

bool good() {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (grid[i][j] < grid[i][j - 1]) { return false; }
        }
    }
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            if (grid[i][j] < grid[i - 1][j]) { return false; }
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    while (!good()) { rotate(); }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
