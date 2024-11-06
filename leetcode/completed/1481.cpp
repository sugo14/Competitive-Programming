#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        if (k >= arr.size()) {
            return 0;
        }
        map<int, int> freq;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (freq.find(arr[i]) == freq.end()) {
                freq[arr[i]] = 1;
                ans++;
            } else {
                freq[arr[i]]++;
            }
        }
        vector<pair<int, int>> sorted = vector<pair<int, int>>(freq.begin(), freq.end());
        sort(sorted.begin(), sorted.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        int x = 0;
        while (k >= 0) {
            k -= sorted[x].second;
            if (k >= 0) { x++; ans--; }
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> arr = {2,1,1,3,3,3};
    int k = 3;
    cout << s.findLeastNumOfUniqueInts(arr, k) << endl;
    return 0;
}
