#include <bits/stdc++.h>
using namespace std;

// lowkey crazy fast because i did the painful int thing
// could be made faster by meet in the middle

bool dead[10001];

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        fill(dead, dead + 10001, false);
        int t = stoi(target);
        for (const string& s : deadends) { dead[stoi(s)] = true; }
        vector<int> curr = {0};
        int ans = 0;
        while (!curr.empty()) {
            vector<int> next;
            for (int x : curr) {
                if (x == t) { return ans; }
                if (dead[x]) { continue; }
                dead[x] = true;
                for (int i = 0; i < 4; i++) {
                    int thing = pow(10, i);
                    int n = x;
                    int dig = (n / thing) % 10;
                    n -= dig * thing;
                    n += ((dig + 1) % 10) * thing;
                    next.push_back(n);
                    n = x - dig * thing;
                    n += ((10 + dig - 1) % 10) * thing;
                    next.push_back(n);
                }
            }
            curr = next;
            ans++;
        }
        if (curr.empty()) { return -1; }
        return ans;
    }
};
