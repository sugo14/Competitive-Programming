#include <bits/stdc++.h>
using namespace std;

int a;

pair<int, int> getDimensions(int area) {
    int x = sqrt(area);
    for (int i = x; i > 0; i--) {
        if (area % i == 0) {
            int side1 = i;
            int side2 = area / i;
            return {side1, side2};
        }
    }
}

int main() {
    cin >> a;
    while (a != 0) {
        std::pair<int, int> d = getDimensions(a);
        int p = (d.first + d.second) * 2;
        cout << "Minimum perimeter is " << p << " with dimensions " << d.first << " x " << d.second << endl;
        cin >> a;
    }
    return 0;
}
