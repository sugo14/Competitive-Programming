#include <bits/stdc++.h>
using namespace std;

/* 
    Problem: https://leetcode.com/problems/minimum-window-substring
    TC: O(n + m)
*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> cInT, foundChars;
        queue<int> positions;
        int bestStart = -1, bestEnd = -1;
        // fill hashmaps
        for (int i = 0; i < 26; i++) {
            cInT[i + 'a'] = 0;
            cInT[i + 'A'] = 0;
            foundChars[i + 'a'] = 0;
            foundChars[i + 'A'] = 0;
        }
        // initialize hashmaps
        for (int i = 0; i < t.size(); i++) {
            char c = t[i];
            cInT[c]++;
            foundChars[c]--;
        }
        // iterate through s, checking for matches
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (cInT[c] == 0) {
                continue;
            }
            positions.push(i);
            foundChars[c]++;
            if (foundChars[c] > 0) {
                while (foundChars[s[positions.front()]] > 0) {
                    foundChars[s[positions.front()]]--;
                    positions.pop(); // TODO: get better data type
                }
            }
            // check if all chars are found
            for (int j = 0; j < 26; j++) {
                if (foundChars[j + 'a'] < 0) {
                    break;
                }
                if (foundChars[j + 'A'] < 0) {
                    break;
                }
                if (j == 25) {
                    int newStart = positions.front();
                    int newEnd = positions.back();
                    if (bestStart == -1 || newEnd - newStart < bestEnd - bestStart) {
                        bestStart = newStart;
                        bestEnd = newEnd;
                    }
                }
            }
        }
        if (bestStart == -1) {
            return "";
        }
        return s.substr(bestStart, bestEnd - bestStart + 1);
    }
};

int main() {
    string s = "ADOBECODEBANC", t = "ABC";
    Solution sol;
    cout << sol.minWindow(s, t) << endl;
}
