#include <bits/stdc++.h>
using namespace std;

// apparently this isnt the smartest way to do this
// in DMOJ comments it said there was an approach where
// you would start from the end and go backwards but
// thats not what i did and it worked

int m, n;
vector<vector<int>> grid;
set<int> visited;
vector<pair<int, int>> factors[1000001];

int main() {
    std::ios_base::sync_with_stdio(0); std::cin.tie(NULL); std::cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        vector<int> row;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            row.push_back(x);
            factors[(i + 1) * (j + 1)].push_back({i, j});
        }
        grid.push_back(row);
    }
    vector<pair<int, int>> curr = {{0, 0}};
    while (curr.size() > 0) {
        vector<pair<int, int>> next;
        for (pair<int, int> e : curr) {
            if (e.first == m - 1 && e.second == n - 1) {
                cout << "yes" << endl;
                return 0;
            }
            int x = grid[e.first][e.second];
            if (visited.find(x) != visited.end()) {
                continue;
            }
            visited.insert(x);
            for (int i = 0; i < factors[x].size(); i++) {
                next.push_back(factors[x][i]);
            }
        }
        curr = next;
    }
    cout << "no" << endl;
    return 0;
}
