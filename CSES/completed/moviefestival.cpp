#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        pair<int, int> time;
        cin >> time.first >> time.second;
        times.push_back(time);
    }
    sort(times.begin(), times.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    int ans = 0, currTime = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> e = times[i];
        if (e.first >= currTime) {
            ans++;
            currTime = e.second;
        }
    }
    cout << ans << endl;
    return 0;
}
