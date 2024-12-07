#include <bits/stdc++.h>
using namespace std;

int main() {
    int r, l;
    cin >> r >> l;
    vector<int> lights(r);
    for (int i = 0; i < r; i++) {
        string bs(l, ' ');
        for (int j = 0; j < l; j++) { cin >> bs[j]; }
        lights[i] = stoi(bs, nullptr, 2);
    }
    reverse(lights.begin(), lights.end());
    unordered_set<int> seen;
    for (int i = 0; i < r; i++) {
        vector<int> newLights = lights;
        for (int j = i; j > 0; j--) { newLights[j - 1] ^= newLights[j]; }
        seen.insert(newLights[0]);
    }
    cout << seen.size() << endl;
    return 0;
}
