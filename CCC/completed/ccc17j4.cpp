#include <bits/stdc++.h>
using namespace std;

std::vector<int> specialTimes;

void setTimes() {
    int hour = 12;
    for (int minute = 0; minute < 60; minute++) {
        int n1 = hour / 10;
        int n2 = hour % 10;
        int n3 = minute / 10;
        int n4 = minute % 10;
        if ((n1 - n2) == (n2 - n3) && (n2 - n3) == (n3 - n4)) {
            specialTimes.push_back(minute);
        }
    }

    for (int hour = 1; hour < 12; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            if (hour >= 10) {
                int n1 = hour / 10;
                int n2 = hour % 10;
                int n3 = minute / 10;
                int n4 = minute % 10;
                if ((n1 - n2) == (n2 - n3) && (n2 - n3) == (n3 - n4)) {
                    specialTimes.push_back(hour * 60 + minute);
                }
            }
            else {
                int n2 = hour % 10;
                int n3 = minute / 10;
                int n4 = minute % 10;
                if ((n2 - n3) == (n3 - n4)) {
                    specialTimes.push_back(hour * 60 + minute);
                }
            }
        }
    }
}

int main() {
    setTimes();
    int n, ans = 0;
    cin >> n;
    ans += (n / 720) * specialTimes.size();
    n %= 720;
    for (int specialTime : specialTimes) {
        if (specialTime > n) {
            break;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
