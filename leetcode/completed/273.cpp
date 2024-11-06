#include <bits/stdc++.h>
using namespace std;

map<long long, string> intToWords = {
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"},
    {6, "Six"},
    {7, "Seven"},
    {8, "Eight"},
    {9, "Nine"},
    {10, "Ten"},
    {11, "Eleven"},
    {12, "Twelve"},
    {13, "Thirteen"},
    {14, "Fourteen"},
    {15, "Fifteen"},
    {16, "Sixteen"},
    {17, "Seventeen"},
    {18, "Eighteen"},
    {19, "Nineteen"},
    {20, "Twenty"},
    {30, "Thirty"},
    {40, "Forty"},
    {50, "Fifty"},
    {60, "Sixty"},
    {70, "Seventy"},
    {80, "Eighty"},
    {90, "Ninety"},
    {100, "Hundred"},
    {1000, "Thousand"},
    {1000000, "Million"},
    {1000000000, "Billion"},
    {1000000000000, "Trillion"}
};

class Solution {
    string segToWords(string seg, int depth) {
        string ans = "";
        int i = stoi(seg);
        if (i == 0) { return ans; }
        if (i < 20) { ans += intToWords[i] + " "; }
        else if (i < 100) {
            ans += intToWords[i / 10 * 10] + " ";
            if (i % 10 != 0) { ans += intToWords[i % 10] + " "; }
        }
        else {
            ans += intToWords[i / 100] + " Hundred ";
            int remain = i % 100;
            if (remain != 0) { ans += segToWords(to_string(remain), 0); }
        }
        if (depth == 0) { return ans; }
        return ans + intToWords[pow(1000, depth)] + " ";
    }
public:
    string numberToWords(int num) {
        if (num == 0) { return "Zero"; }
        string newNum = to_string(num), ans = "";
        reverse(newNum.begin(), newNum.end());
        vector<string> numSegments;
        for (int i = 0; i < newNum.size(); i += 3) { numSegments.push_back(newNum.substr(i, min(3, (int) newNum.size() - i + 1))); }
        for (int i = 0; i < numSegments.size(); i++) { reverse(numSegments[i].begin(), numSegments[i].end()); }
        for (int i = numSegments.size() - 1; i >= 0; i--) { ans += segToWords(numSegments[i], i); }
        ans.pop_back();
        return ans;
    }
};