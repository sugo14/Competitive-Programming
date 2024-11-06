#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
std::vector<int> top, bottom;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        top.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        bottom.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        ans += top[i] * 3 + bottom[i] * 3;
        if (top[i] && bottom[i] && !(i % 2)) {
            ans -= 2;
        }
        if (i != n - 1) {
            if (top[i] && top[i + 1]) {
                ans -= 2;
            }
            if (bottom[i] && bottom[i + 1]) {
                ans -= 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
