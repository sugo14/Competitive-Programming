#include <bits/stdc++.h>
using namespace std;

// scuffed

class Solution {
    int cnt[26], rep = 0, curr = 25;
    string ans;
public:
    string repeatLimitedString(string s, int repeatLimit) {
        for (char c : s) { cnt[c - 'a']++; }
        while (curr >= 0) {
            while (curr >= 0 && cnt[curr] == 0) {
                rep = 0;
                curr--;
            }
            if (curr < 0) { return ans; }
            if (rep == repeatLimit) {
                int next = curr - 1;
                while (next >= 0 && cnt[next] == 0) { next--; }
                if (next < 0) { return ans; }
                ans += next + 'a';
                cnt[next]--;
                rep = 0;
            }
            else {
                ans += curr + 'a';
                cnt[curr]--;
                rep++;
            }
        }
        return ans;
    }
};
