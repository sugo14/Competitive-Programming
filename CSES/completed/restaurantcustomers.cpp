#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> starts;
    priority_queue<int, vector<int>, greater<int>> ends;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        starts.push(s);
        ends.push(e);
    }
    int curr = 0, big = 0;
    while (starts.size() > 0) {
        curr++;
        while (ends.top() <= starts.top()) {
            ends.pop();
            curr--;
        }
        starts.pop();
        big = max(big, curr);
    }
    cout << big << endl;
    return 0;
}
