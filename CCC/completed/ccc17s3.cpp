#include <bits/stdc++.h>
using namespace std;

int l[2001];
int l2[4000002];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        l[x]++;
    }
    for (int i = 0; i < 2001; i++) {
        l2[i * 2] += l[i] / 2;
        for (int j = i + 1; j < 2001; j++) {
            l2[i + j] += min(l[i], l[j]);
        }
    }
    int max = 0, maxI = 0;
    for (int i = 0; i < 4000002; i++) {
        if (l2[i] > max) {
            max = l2[i];
            maxI = 1;
        }
        else if (l2[i] == max) {
            maxI++;
        }
    }
    cout << max << " " << maxI << endl;
}
