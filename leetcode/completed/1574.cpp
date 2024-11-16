#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        arr.insert(arr.begin(), 0);
        arr.push_back(1e9 + 5);
        int l = 0, r = arr.size() - 1;
        while (l < arr.size() - 2 && arr[l] <= arr[l + 1]) { l++; }
        int minLength = r - l - 1;
        for (; l >= 0; l--) {
            while (l < r - 1 && arr[l] <= arr[r - 1] && arr[r - 1] <= arr[r]) { r--; }
            minLength = min(minLength, r - l - 1);
        }
        return minLength;
    }
};
