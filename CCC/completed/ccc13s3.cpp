#include <bits/stdc++.h>
using namespace std;

int t, g, ans;
vector<pair<int, int>> order = {
    {0, 1},
    {0, 2},
    {0, 3},
    {1, 2},
    {1, 3},
    {2, 3}
};
bool roundDone[4][4];
int scores[4];

void runRound(int n) {
    if (n == 6) {
        int score = scores[t];
        bool wins = true;
        for (int i = 0; i < 4; i++) {
            if (i == t) { continue; }
            if (scores[i] >= score) { wins = false; }
        }
        if (wins) { ans++; }
        return;
    }
    if (roundDone[order[n].first][order[n].second]) {
        runRound(n + 1);
    }
    else {
        scores[order[n].first]++;
        scores[order[n].second]++;
        runRound(n + 1);
        scores[order[n].first]--;
        scores[order[n].second]--;

        scores[order[n].first] += 3;
        runRound(n + 1);
        scores[order[n].first] -= 3;

        scores[order[n].second] += 3;
        runRound(n + 1);
        scores[order[n].second] -= 3;
    }
}

int main() {
    cin >> t >> g;
    t--;
    for (int i = 0; i < g; i++) {
        int a, b, sa, sb;
        cin >> a >> b >> sa >> sb;
        a--; b--;
        if (sa == sb) {
            scores[a]++;
            scores[b]++;
        }
        else if (sa > sb) {
            scores[a] += 3;
        }
        else {
            scores[b] += 3;
        }
        roundDone[a][b] = true;
        roundDone[b][a] = true;
    }
    runRound(0);
    cout << ans << endl;
    return 0;
}
