#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> grouped;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> freq = vector<int>(26, 0);
            string str = strs[i];
            for (int j = 0; j < str.size(); j++) {
                freq[str[j] - 'a']++;
            }
            if (grouped.count(freq)) {
                grouped[freq].push_back(str);
            }
            else {
                vector<string> v;
                v.push_back(str);
                grouped[freq] = v;
            }
        }
        vector<vector<string>> ans = {};
        for (auto pair : grouped) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans = s.groupAnagrams(strs);
    for (auto v : ans) {
        for (auto s : v) {
            cout << s << " ";
        }
        cout << endl;
    }
}
