#include <bits/stdc++.h>
using namespace std;

// short dp sols will never not be funny
class Solution {
    int arr[100001];
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    vector<int> ans;
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        for (int i = 0; i < words.size(); i++) { arr[i + 1] = arr[i] + (count(vowels.begin(), vowels.end(), words[i][0]) && count(vowels.begin(), vowels.end(), words[i][words[i].size() - 1])); }
        for (auto& q : queries) { ans.push_back(arr[q[1] + 1] - arr[q[0]]); }
        return ans;
    }
};
