#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string best = "";
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            best = (best.size() < right - left - 1) ? s.substr(left + 1, right - left - 1) : best;
            left = i - 1, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            best = (best.size() < right - left - 1) ? s.substr(left + 1, right - left - 1) : best;
        }
        return best;
    }
};
