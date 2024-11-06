#include <bits/stdc++.h>
using namespace std;

int n;
double ans = 0;
std::vector<int> sideLengths = {};

int main() {
    cin >> n;
    for (int i = 0; i < n + 1; i++) {
        int a;
        cin >> a;
        sideLengths.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        double base;
        cin >> base;
        double left = sideLengths[i];
        double right = sideLengths[i + 1];
        double squareHeight = min(left, right);
        ans += base * squareHeight;
        double triangleHeight = max(left, right) - squareHeight;
        ans += base * triangleHeight / 2;
    }
    cout << fixed << ans << endl;
    return 0;
}
