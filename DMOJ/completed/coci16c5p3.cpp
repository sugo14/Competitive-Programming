#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

int cols[10000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w, h;
        cin >> w >> h;
        cols[w] = max(cols[w], h);
    }
    int big = 0;
    ull ans = 0;
    for (ull i = 10000000; i >= 1; i--) {
        big = max(big, cols[i]);
        ans += big;
    }
    cout << ans << endl;
}
