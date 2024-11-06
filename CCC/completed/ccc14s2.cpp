#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<string> names;
    bool good = true;
    vector<pair<string, string>> pairs(n);
    set<pair<string, string>> seenPairs;
    for (int i = 0; i < n; i++) { cin >> pairs[i].first; }
    for (int i = 0; i < n; i++) { cin >> pairs[i].second; }
    for (int i = 0; i < n; i++) {
        string a = pairs[i].first, b = pairs[i].second;
        if (a == b) {
            good = false;
            break;
        }
        if (names.find(a) != names.end() || names.find(b) != names.end()) {
            if (seenPairs.find({a, b}) == seenPairs.end()) {
                good = false;
                break;
            }
        }
        names.insert(a);
        names.insert(b);
        seenPairs.insert({a, b});
        seenPairs.insert({b, a});
    }
    cout << (good ? "good" : "bad") << endl;
    return 0;
}
