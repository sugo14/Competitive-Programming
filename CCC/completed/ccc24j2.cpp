#include <bits/stdc++.h>
using namespace std;

int main() {
    int r;
    cin >> r;
    while (true) {
        int x;
        cin >> x;
        if (r <= x) {
            cout << r << endl;
            return 0;
        }
        r += x;
    }
}
