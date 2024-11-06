#include <bits/stdc++.h>
using namespace std;

set<pair<string, string>> friends;
set<pair<string, string>> enemies;

int main() {
    int n, m, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        friends.insert({a, b});
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        enemies.insert({a, b});
    }
    int ans = 0;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string curr[3];
        cin >> curr[0] >> curr[1] >> curr[2];
        for (int j = 0; j < 3; j++) {
            for (int k = j + 1; k < 3; k++) {
                if (friends.find({curr[j], curr[k]}) != friends.end()) {
                    friends.erase({curr[j], curr[k]});
                }
                if (friends.find({curr[k], curr[j]}) != friends.end()) {
                    friends.erase({curr[k], curr[j]});
                }
                if (enemies.find({curr[j], curr[k]}) != enemies.end()) {
                    enemies.erase({curr[j], curr[k]});
                    ans++;
                }
                if (enemies.find({curr[k], curr[j]}) != enemies.end()) {
                    enemies.erase({curr[k], curr[j]});
                    ans++;
                }
            }
        }
    }
    ans += friends.size();
    cout << ans << endl;
    return 0;
}
