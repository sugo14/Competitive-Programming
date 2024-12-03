#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string newS;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            while (j < spaces.size() && spaces[j] < i) { j++; }
            if (j < spaces.size() && spaces[j] == i) { newS += " "; }
            newS += s[i];
        }
        return newS;
    }
};
