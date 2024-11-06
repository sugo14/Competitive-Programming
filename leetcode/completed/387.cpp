#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        int seen[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            seen[s[i] - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (seen[s[i] - 'a'] < 2) {
                return i;
            }
        }
        return -1;
    }
};
