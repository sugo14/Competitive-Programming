#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getIndex(char c) {
        if (c >= 'a') {
            return c - 'a' + 36;
        }
        else if (c >= 'A') {
            return c - 'A' + 10;
        }
        else {
            return c - '0';
        }
    }
    char getChar(int index) {
        if (index >= 36) {
            return index - 36 + 'a';
        }
        else if (index >= 10) {
            return index - 10 + 'A';
        }
        else {
            return index + '0';
        }
    }
public:
    string frequencySort(string s) {
        vector<pair<int, int>> v; // { character, quantity }
        for (int i = 0; i < 62; i++) {
            v.push_back({i, 0});
        }
        for (char c : s) {
            v[getIndex(c)].second++;
        }
        std::sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second > b.second;
        });
        string ans;
        for (auto pair : v) {
            ans += string(pair.second, getChar(pair.first));
        }
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.frequencySort("tree") << endl;
    cout << s.frequencySort("cccaaa") << endl;
    cout << s.frequencySort("Aabb") << endl;
}
