#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long y, x;
        cin >> y >> x;
        long long n = max(y, x);
        long long epicNum = n * n;
        if (n % 2 == 0) {
            cout << epicNum - x + 1 - n + y << endl;
        }
        else {
            cout << epicNum - y + 1 - n + x << endl;
        }
    }
    return 0;
}
