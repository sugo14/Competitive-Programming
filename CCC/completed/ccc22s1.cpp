#include <bits/stdc++.h>
using namespace std;

std::pair<int, int> initial(int n) {
    std::pair<int, int> nums = {0, 0}; // {#of4s, #of5s}
    int x = 0;
    while (x < n) {
        x += 5;
        nums.second++;
    }
    while (x != n) {
        nums.first++;
        nums.second--;
        x -= 1;
    }
    return nums;
}

int total, ans = 0;

int main() {
    cin >> total;
    std::pair<int, int> nums = initial(total);
    if (nums.first < 0 || nums.second < 0) {
        cout << 0 << endl;
        return 0;
    }
    ans++;
    ans += nums.first / 5;
    ans += nums.second / 4;
    cout << ans << endl;
    return 0;
}
