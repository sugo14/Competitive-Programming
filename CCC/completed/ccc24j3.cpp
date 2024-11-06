#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> scores;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        scores.push_back(x);
    }
    sort(scores.begin(), scores.end());
    int n1 = INT_MIN, n2 = INT_MIN, n3 = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int x = scores[scores.size() - i - 1];
        if (n1 == INT_MIN || x == n1) {
            n1 = x;
        }
        else if (n2 == INT_MIN || x == n2) {
            n2 = x;
        }
        else if (n3 == INT_MIN || x == n3) {
            n3 = x;
            count++;
        }
        else {
            cout << n3 << " " << count << endl;
            return 0;
        }
    }
    cout << n3 << " " << count << endl;
    return 0;
}
