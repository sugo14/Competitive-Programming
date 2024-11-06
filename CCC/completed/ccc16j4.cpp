#include <bits/stdc++.h>
using namespace std;

int depart;
std::vector<std::pair<int, int>> rushTimes = {
    {7 * 60, 10 * 60},
    {15 * 60, 19 * 60}
};

int main() {
    string departStr;
    cin >> departStr;
    depart = stoi(departStr.substr(0, 2)) * 60 + stoi(departStr.substr(3, 2));

    int t = depart;
    for (int d = 0; d < 120; d++) {
        if (t >= rushTimes[0].first && t < rushTimes[0].second) {
            t += 2;
        }
        else if (t >= rushTimes[1].first && t < rushTimes[1].second) {
            t += 2;
        }
        else {
            t += 1;
        }
        if (t >= 24 * 60) {
            t -= 24 * 60;
        }
    }

    string ans;
    ans = to_string(t / 60);
    t %= 60;
    for (int i = ans.size(); i < 2; i++) {
        ans = "0" + ans;
    }
    ans += ":";
    for (int i = to_string(t).size(); i < 2; i++) {
        ans += "0";
    }
    ans += to_string(t);
    cout << ans << endl;
    return 0;
}
