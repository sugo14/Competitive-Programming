#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefix;
        for (int i : arr1) {
            string e = to_string(i);
            for (int i = 0; i < e.size(); i++) { prefix.insert(e.substr(0, i + 1)); }
        }
        int big = 0;
        for (int i : arr2) {
            string e = to_string(i);
            for (int i = big; i < e.size(); i++) {
                if (prefix.find(e.substr(0, i + 1)) != prefix.end()) { big = max(big, i + 1); }
            }
        }
        return big;
    }
};
