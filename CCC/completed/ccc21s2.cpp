#include <bits/stdc++.h>
using namespace std;

vector<bool> rows, cols;
int r, c, n, funny = 0, ans = 0;

int main() {
    cin >> r >> c;
    rows = vector<bool>(r, 0);
    cols = vector<bool>(c, 0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        char z;
        cin >> z >> x;
        x -= 1;
        if (z == 'R') {
            rows[x] = !rows[x];
        }
        else {
            cols[x] = !cols[x];
        }
    }
    for (int i = 0; i < rows.size(); i++) {
        if (rows[i]) {
            ans += c;
            funny++;
        }
    }
    for (int j = 0; j < cols.size(); j++) {
        if (cols[j]) {
            ans += r;
            ans -= funny * 2;
        }
    }
    cout << ans << endl;
}
