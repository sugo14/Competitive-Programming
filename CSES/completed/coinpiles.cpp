#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            swap(a, b);
        }
        if (a > 2 * b || (a + b) % 3 != 0) {
            cout << "NO" << endl;
        }
        else {
            cout << "YES" << endl;
        }
    }
}
