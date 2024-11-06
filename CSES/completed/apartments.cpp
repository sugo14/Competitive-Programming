#include <bits/stdc++.h>
using namespace std;

#define ull long long

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ull> ppl(n), buildings(m);
    for (int i = 0; i < n; i++) {
        cin >> ppl[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> buildings[i];
    }
    sort(ppl.begin(), ppl.end());
    sort(buildings.begin(), buildings.end());
    int buildingsI = 0, ans = 0;
    for (int pplI = 0; pplI < n; pplI++) {
        ull person = ppl[pplI];
        ull building = buildings[buildingsI];
        while (building < person - k && buildingsI < m) {
            buildingsI++;
            building = buildings[buildingsI];
        }
        if (buildingsI == m) { break; }
        if (building >= person - k && building <= person + k) {
            ans++;
            buildingsI++;
        }
        if (buildingsI == m) { break; }
    }
    cout << ans << endl;
}
