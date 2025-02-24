#include <bits/stdc++.h>
using namespace std;

#define printv(x) for (int i = 0; i < x.size(); i++) { cout << x[i] << " "; } cout << endl;

int h, k;
vector<int> houses;

int hydrantsNeeded(int dist) {
    int minCnt = 1000001;
    for (int j = 0; j < houses.size(); j++) {
        // cyclic shift the houses
        vector<int> currhouses;
        for (int i = j; i < houses.size(); i++) { currhouses.push_back(houses[i] - houses[j]); }
        for (int i = 0; i < j; i++) { currhouses.push_back(houses[i] + 1000000 - houses[j]); }

        int lastHydrant = currhouses[0] + dist, cnt = 1;
        for (int i = 1; i < currhouses.size(); i++) {
            if (currhouses[i] - lastHydrant > dist) {
                lastHydrant = currhouses[i] + dist;
                cnt++;
            }
        }
        
        minCnt = min(minCnt, cnt);
    }
    return minCnt;
}

int bs() {
    int l = 0, r = 500000;
    while (l < r) {
        int mid = (l + r) / 2;
        int hyd = hydrantsNeeded(mid);
        if (hyd <= k) { r = mid; }
        else { l = mid + 1; }
    }
    return l;
}

int main() {
    cin >> h;
    houses.resize(h);
    for (int i = 0; i < h; i++) { cin >> houses[i]; }
    sort(houses.begin(), houses.end());
    cin >> k;
    cout << bs() << endl;
    return 0;
}
