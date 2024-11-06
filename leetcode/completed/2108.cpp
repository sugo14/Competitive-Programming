#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            int left = ceil(s.size() / 2) - ((s.size() % 2 == 0) ? 1 : 0);
            int right = ceil(s.size() / 2);
            while (left >= 0 && right < s.size()) {
                char e1 = s[left], e2 = s[right];
                if (e1 != e2) {
                    break;
                }
                else if (left == 0) {
                    return words[i];
                }
                left--;
                right++;
            }
        }
        return "";
    }
};
