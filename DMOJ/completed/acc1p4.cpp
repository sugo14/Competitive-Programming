#include <bits/stdc++.h>
using namespace std;

int arr[200001];
set<int> unsorted;

int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) { cin >> arr[i]; }
    for (int i = 0; i < n; i++) {
        if (arr[i] < arr[(i - 1 + n) % n]) { unsorted.insert(i); }
    }
    for (int i = 0; i < q; i++) {
        int I, X;
        cin >> I >> X;
        I--;
        arr[I] = X;
        if (arr[I] < arr[(I - 1 + n) % n]) { unsorted.insert(I); }
        else {
            if (unsorted.find(I) != unsorted.end()) { unsorted.erase(I); }
        }
        if (arr[(I + 1) % n] < arr[I]) { unsorted.insert((I + 1) % n); }
        else {
            if (unsorted.find((I + 1) % n) != unsorted.end()) { unsorted.erase((I + 1) % n); }
        }
        if (unsorted.size() >= 2) { cout << -1 << endl; }
        else if (unsorted.size() == 1) {
            int x = *unsorted.begin();
            int y = n - x;
            cout << min(x, y) << endl;
        }
        else { cout << 0 << endl; }
    }
}
