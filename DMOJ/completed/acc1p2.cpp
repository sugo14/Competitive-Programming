#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if (b == 1) {
        cout << (a > 1 ? 2 : 1) << '\n';
        for (int i = 0; i < a; i++) { cout << 1 + i % 2 << '\n'; }
        return 0;
    }
    cout << (1 + (b >= 2) + (a >= 2) * 2) << '\n';
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) { cout << 1 + j % 2 + i % 2 * 2 << ' '; }
        cout << '\n';
    }
}
