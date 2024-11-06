#include <bits/stdc++.h>
using namespace std;

int cache[5001];
int n;
vector<int> v;

int main() {
    fill(cache, cache + 5001, INT_MAX);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        int sum = 0, left = i, right = i;
        while (left >= 0 && right < n) {
            sum += abs(v[right] - v[left]);
            cache[right - left] = min(sum, cache[right - left]);
            left--;
            right++;
        }
        sum = 0, left = i, right = i + 1;
        while (left >= 0 && right < n) {
            sum += abs(v[right] - v[left]);
            cache[right - left] = min(sum, cache[right - left]);
            left--;
            right++;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << cache[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    return 0;
}
