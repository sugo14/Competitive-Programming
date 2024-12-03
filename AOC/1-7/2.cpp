#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> reps;

bool isGoodReading(vector<int> reading) {
    vector<int> r1 = reading, r2 = reading;
    sort(r1.begin(), r1.end());
    sort(r2.begin(), r2.end(), greater<int>());
    if (r1 != reading && r2 != reading) { return false; }

    for (int i = 1; i < reading.size(); i++) {
        int dif = abs(reading[i] - reading[i - 1]);
        if (dif > 3 || dif == 0) { return false; }
    }
    return true;
}

bool isGood(vector<int> ogReading) {
    if (isGoodReading(ogReading)) { return true; }
    for (int i = 0; i < ogReading.size(); i++) {
        vector<int> reading = ogReading;
        reading.erase(reading.begin() + i);
        if (isGoodReading(reading)) { return true; }
    }
    return false;
}

int main() {
    freopen("2.in", "r", stdin);
    reps = vector<vector<int>>(1000, vector<int>());
    for (int i = 0; i < 1000; i++) {
        string line;
        getline(cin, line);
        istringstream iss(line);
        while (iss) {
            int x;
            iss >> x;
            reps[i].push_back(x);
        }
        reps[i].pop_back();
    }
    int ans = 0;
    for (int i = 0; i < 1000; i++) {
        ans += isGood(reps[i]);
    }
    cout << ans << endl;
}
