#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                ans++;
                left--;
                right++;
            }
            left = i - 1, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                ans++;
                left--;
                right++;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
