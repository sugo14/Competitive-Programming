#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> visited;
pair<int, int> start, target;

bool canMove(pair<int, int> p) {
    int j = p.first, k = p.second;
    if (j < 0 || j > 7 || k < 0 || k > 7) {
        return false;
    } 
    if (!visited.count({j, k})) {
        visited.insert({j, k});
        return true;
    }
    return false;
}

int bfs() {
    if (start == target) {
        return 0;
    }
    int ans = 1;
    vector<pair<int, int>> at = {start};
    vector<pair<int, int>> next;
    while (true) {
        for (pair<int, int> e : at) {
            for (int x = -2; x <= 2; x++) {
                if (x == 0) { continue; }
                int y = (x == 2 || x == -2) ? 1 : 2;
                pair<int, int> p = {e.first + x, e.second + y};
                if (p == target) {
                    return ans;
                }
                if (canMove(p)) {
                    // cout << "p: " << p.first << " " << p.second << endl;
                    next.push_back(p);
                }
                p = {e.first + x, e.second - y};
                if (p == target) {
                    return ans;
                }
                if (canMove(p)) {
                    // cout << "p: " << p.first << " " << p.second << endl;
                    next.push_back(p);
                }
            }
        }
        ans++;
        at = next;
    }
}

int main() {
    cin >> start.first >> start.second >> target.first >> target.second;
    start.first--; start.second--; target.first--; target.second--;
    cout << bfs() << endl;
    return 0;
}
