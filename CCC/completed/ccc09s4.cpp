#include <bits/stdc++.h>
using namespace std;

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

/* #define int long long */

vector<pair<int, int>> adj[5001] = {};
int seintingPrice[5001];
int dist[5001];
bool visited[5001];

void shortestPath(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty()) {
        int currDist = pq.top().first;
        int currNode = pq.top().second;
        pq.pop();
        visited[currNode] = true;
        if (currDist > dist[currNode]) { continue; }
        for (auto& x : adj[currNode]) {
            int edgeNext = x.first;
            int edgeCost = x.second;
            if (visited[edgeNext]) { continue; }
            if (currDist + edgeCost < dist[edgeNext]) {
                dist[edgeNext] = currDist + edgeCost;
                pq.push({currDist + edgeCost, edgeNext});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    fill(dist, dist + 5001, INT_MAX);
    fill(visited, visited + 5001, false);
    fill(seintingPrice, seintingPrice + 5001, INT_MAX);
    int n, t;
    scan(n); scan(t);
    for (int i = 0; i < t; i++) {
        int start, end, cost;
        scan(start); scan(end); scan(cost);
        adj[start].push_back({end, cost});
        adj[end].push_back({start, cost});
    }
    int k;
    scan(k);
    for (int i = 0; i < k; i++) {
        int node, price;
        scan(node); scan(price);
        seintingPrice[node] = price;
    }
    int start;
    scan(start);
    dist[start] = 0;
    shortestPath(start);
    int smaint = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (seintingPrice[i] != INT_MAX && dist[i] != INT_MAX) {
            smaint = min(smaint, dist[i] + seintingPrice[i]);
        }
    }
    cout << smaint << endl;
    return 0;
}
