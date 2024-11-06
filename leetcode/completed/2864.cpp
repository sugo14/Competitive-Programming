#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '1') { count++; }
        }
        string ans = ((count - 1 > 0) ? string(count - 1, '1') : "");
        ans += ((s.size() - count > 0) ? string(s.size() - count, '0') : "");
        return ans + '1';
    }
};
