#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> book;
    vector<bool> visitable(n, false);
    for (int i = 0; i < n; i++) {
        vector<int> v;
        int x;
        cin >> x;
        for (int j = 0; j < x; j++) {
            int y;
            cin >> y;
            v.push_back(y - 1);
        }
        book.push_back(v);
    }
    int ans = 1;
    bool ansFound = false;
    vector<int> curr = {0};
    unordered_set<int> visited;
    while (curr.size() > 0) {
        vector<int> next;
        for (int e : curr) {
            vector<int> paths = book[e];
            if (paths.size() == 0) {
                ansFound = true;
            }
            for (int f : paths) {
                if (visited.find(f) == visited.end()) {
                    visitable[f] = true;
                    next.push_back(f);
                    visited.insert(f);
                }
            }
        }
        curr = next;
        if (!ansFound) { ans++; }
    }
    if (find(visitable.begin() + 1, visitable.end(), false) != visitable.end()) {
        cout << "N" << "\n";
    }
    else {
        cout << "Y" << "\n";
    }
    cout << ans << endl;
    return 0;
}
