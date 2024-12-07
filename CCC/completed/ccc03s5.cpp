#include <bits/stdc++.h>
using namespace std;

int c, r, d;
map<int, vector<pair<int, int>>> adj;
vector<int> destCities;
int maxWeight[100005];

priority_queue<pair<int, int>> pq;

int main() {
    cin >> c >> r >> d;
    for (int i = 0; i < r; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    destCities = vector<int>(d);
    for (int i = 0; i < d; i++) { cin >> destCities[i]; }
    for (int i = 1; i <= c; i++) { maxWeight[i] = INT_MIN; }
    pq.push({INT_MAX, 1});
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        if (maxWeight[top.second] != INT_MIN) { continue; }
        maxWeight[top.second] = top.first;
        int weight = top.first, city = top.second;
        for (auto& x : adj[city]) {
            int nextCity = x.first, nextWeight = min(weight, x.second);
            if (maxWeight[nextCity] == INT_MIN) {
                pq.push({nextWeight, nextCity});
            }
        }
    }

    int small = INT_MAX;
    for (int i = 0; i < d; i++) {
        small = min(small, maxWeight[destCities[i]]);
    }
    cout << small << endl;
    return 0;
}
