#include <bits/stdc++.h>
using namespace std;

struct c {
    int x, y;

    c(int x, int y) : x(x), y(y) {}

    bool operator==(const c &other) const {
        return x == other.x && y == other.y;
    }

    friend ostream &operator<<(ostream &os, const c &c1) {
        return os << c1.x << " " << c1.y;
    }
};

int t, m, x, y;

c fit(c curr, int minX, int minY, int currDepth) {
    for (int i = 0; i < currDepth; i++) {
        int newX = curr.x / 5, newY = curr.y / 5;
        curr.x = newX, curr.y = newY;
    }
    return curr;
}

bool window(int minX, int minY, int currDepth = 0) {
    c fitted = fit({x, y}, minX, minY, m - currDepth - 1);
    fitted.x -= minX;
    fitted.y -= minY;
    if (fitted == c(1, 0) || fitted == c(2, 0) || fitted == c(3, 0) || fitted == c(2, 1)) { return true; }
    if (fitted == c(1, 1) || fitted == c(2, 2) || fitted == c(3, 1)) {
        int X = minX * 5, Y = minY * 5;
        return window(X + 5, Y + 5, currDepth+1) || window(X + 10, Y + 10, currDepth+1) || window(X + 15, Y + 5, currDepth+1);
    }
    return false;
}

int main() {
    cin >> t;
    while (t--) {
        cin >> m >> x >> y;
        cout << (window(0, 0) ? "crystal" : "empty") << endl;
    }
}
