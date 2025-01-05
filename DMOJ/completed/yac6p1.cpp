#include <bits/stdc++.h>
using namespace std;

// "graph theory" without graph but i had to think about a graph so i guess it works

int n, m;

int main() {
    cin >> n >> m;
    int rep = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + 1 << ' ' << j + 1 << endl;
            rep++;
            if (rep == m) {
                return 0;
            }
        }
    }
    return 0;
}
