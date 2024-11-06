#include <bits/stdc++.h>
using namespace std;

int v[101];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v, v + n);
    int low = n / 2 - 1;
    if (n % 2 == 1) { low++; }
    int high = low + 1;
    while (low >= 0) {
        cout << v[low] << " ";
        low--;
        if (high < n) { cout << v[high] << " "; }
        high++;
    }
    cout << endl;
    return 0;
}
