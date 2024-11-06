#include <bits/stdc++.h>
using namespace std;

std::vector<std::pair<int, int>> activeMessages = {};
// {friend#, sendTime}
std::vector<int> totalWaitTimes = std::vector<int>(101, 0);
// v[friend#] = total wait time
int t = 0;

int main() {
    int n;
    cin >> n;
    char lastC = 'W';
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (lastC != 'W' && c != 'W') {
            t++;
        }
        if (c == 'R') {
            activeMessages.push_back({x, t});
        }
        else if (c == 'W') {
            t += x;
        }
        else if (c == 'S') {
            auto startTime = find_if(activeMessages.begin(), activeMessages.end(), [&](const std::pair<int, int>& p) { return p.first == x; });
            totalWaitTimes[x] += t - startTime->second;
            activeMessages.erase(startTime);
        }
        lastC = c;
    }
    for (auto message : activeMessages) {
        totalWaitTimes[message.first] = -1;
    }
    for (int i = 0; i < 101; i++) {
        if (totalWaitTimes[i] != 0) {
            cout << i << " " << totalWaitTimes[i] << endl;
        }
    }
    return 0;
}
