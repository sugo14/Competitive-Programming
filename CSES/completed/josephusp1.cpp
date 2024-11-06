#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i + 1);
    }
    bool odd = true;
    while (!q.empty()) {
        queue<int> next;
        while (!q.empty()) {
            if (odd) {
                int x = q.front();
                next.push(x);
                q.pop();
            }
            else {
                int x = q.front();
                cout << x << " ";
                q.pop();
            }
            odd = !odd;
        }
        q = next;
    }
    cout << endl;
    return 0;
}
