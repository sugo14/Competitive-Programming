#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int last;
    cin >> last;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        if (x <= last) {
            ans += last - x;
        }
        else {
            last = x;
        }
    }
    cout << ans << endl;
    return 0;
}
