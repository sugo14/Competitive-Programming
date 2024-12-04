#include <bits/stdc++.h>
using namespace std;

class Solution {
    char mod(char c, int i) { return (c - 'a' + 26 + i) % 26 + 'a'; }
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0;
        for (char c : str1) {
            char d = str2[i];
            if (c == d || mod(c, 1) == d) { i++; }
            if (i == str2.size()) { break; }
        }
        return i == str2.size();
    }
};
