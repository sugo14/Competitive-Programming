#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> circle;
    for (int i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        circle.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        if (x == circle[i]) {
            ans += 2;
        }
    }
    cout << ans << endl;
    return 0;
}
